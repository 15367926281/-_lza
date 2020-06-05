#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "waypoint.h"
#include "enemy.h"
#include "bullet.h"
#include "plistreader.h"
#include <QPainter>
#include <QMouseEvent>
#include <QtGlobal>
#include <QMessageBox>
#include <QTimer>
#include <QXmlStreamReader>
#include <QtDebug>

static const int TowerCost = 300;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
    , m_waves(0)
    , m_playerHp(1)
	, m_playrGold(1000)
    , m_gameEnded(false)
    , m_gameWin(false)
{
	ui->setupUi(this);

	preLoadWavesInfo();
	loadTowerPositions();
	addWayPoints();
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(updateMap()));
	timer->start(30);
	// 设置300ms后游戏启动
	QTimer::singleShot(300, this, SLOT(gameStart()));
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{//鼠标点击实现塔的出现
	QPoint pressPos = event->pos();
	auto it = m_towerPositionsList.begin();
	while (it != m_towerPositionsList.end())
	{
		if (canBuyTower() && it->containPoint(pressPos) && !it->hasTower())
		{
            m_playrGold -= TowerCost;
			it->setHasTower();

			Tower *tower = new Tower(it->centerPos(), this);
            m_towersList.push_back(tower);//把新塔加入
			update();
			break;
		}
		++it;
	}
}
//判断是否能购买炮塔
bool MainWindow::canBuyTower() const
{
	if (m_playrGold >= TowerCost)
		return true;
	return false;
}
//绘制波数
void MainWindow::drawWave(QPainter *painter)
{
	painter->setPen(QPen(Qt::red));
	painter->drawText(QRect(400, 5, 100, 25), QString("WAVE : %1").arg(m_waves + 1));
}
//绘制血量
void MainWindow::drawHP(QPainter *painter)
{
	painter->setPen(QPen(Qt::red));
	painter->drawText(QRect(30, 5, 100, 25), QString("HP : %1").arg(m_playerHp));
}
//绘制钱
void MainWindow::drawPlayerGold(QPainter *painter)
{
	painter->setPen(QPen(Qt::red));
	painter->drawText(QRect(200, 5, 200, 25), QString("GOLD : %1").arg(m_playrGold));
}
//游戏结束场景
void MainWindow::doGameOver()
{
	if (!m_gameEnded)
	{
		m_gameEnded = true;
	}
}
//获得金币
void MainWindow::awardGold(int gold)
{
	m_playrGold += gold;
	update();
}
void MainWindow::addWayPoints()
{//敌人的行走路线
	WayPoint *wayPoint1 = new WayPoint(QPoint(420, 285));
	m_wayPointsList.push_back(wayPoint1);

	WayPoint *wayPoint2 = new WayPoint(QPoint(35, 285));
	m_wayPointsList.push_back(wayPoint2);
	wayPoint2->setNextWayPoint(wayPoint1);

	WayPoint *wayPoint3 = new WayPoint(QPoint(35, 195));
	m_wayPointsList.push_back(wayPoint3);
	wayPoint3->setNextWayPoint(wayPoint2);

	WayPoint *wayPoint4 = new WayPoint(QPoint(445, 195));
	m_wayPointsList.push_back(wayPoint4);
	wayPoint4->setNextWayPoint(wayPoint3);

	WayPoint *wayPoint5 = new WayPoint(QPoint(445, 100));
	m_wayPointsList.push_back(wayPoint5);
	wayPoint5->setNextWayPoint(wayPoint4);

	WayPoint *wayPoint6 = new WayPoint(QPoint(35, 100));
	m_wayPointsList.push_back(wayPoint6);
	wayPoint6->setNextWayPoint(wayPoint5);
}
//基地降低函数
void MainWindow::getHpDamage(int damage/* = 1*/)
{
	m_playerHp -= damage;
	if (m_playerHp <= 0)
		doGameOver();
}
//清除敌人
void MainWindow::removedEnemy(Enemy *enemy)
{
	Q_ASSERT(enemy);

	m_enemyList.removeOne(enemy);
	delete enemy;

	if (m_enemyList.empty())
	{
		++m_waves;
		if (!loadWave())
		{
            //所有的波数全部度过时游戏胜利
			m_gameWin = true;
		}
	}
}
//清除子弹
void MainWindow::removedBullet(Bullet *bullet)
{
	Q_ASSERT(bullet);
	m_bulletList.removeOne(bullet);
	delete bullet;
}
//子弹
void MainWindow::addBullet(Bullet *bullet)
{
	Q_ASSERT(bullet);

	m_bulletList.push_back(bullet);
}
//进行移动
void MainWindow::updateMap()
{
	foreach (Enemy *enemy, m_enemyList)
		enemy->move();
	foreach (Tower *tower, m_towersList)
		tower->checkEnemyInRange();
	update();
}
//初始数据
void MainWindow::preLoadWavesInfo()
{
    QFile file(":/config/Waves.plist");//把初使数据写到文件里去
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "TowerDefense", "Cannot Open TowersPosition.plist");
        return;
    }
	PListReader reader;
	reader.read(&file);
	// 获取波数信息
	m_wavesInfo = reader.data();
	file.close();
}
//关于下一波敌人的数目与时间的实现
bool MainWindow::loadWave()
{
	if (m_waves >= m_wavesInfo.size())
		return false;
	WayPoint *startWayPoint = m_wayPointsList.back();
	QList<QVariant> curWavesInfo = m_wavesInfo[m_waves].toList();
	for (int i = 0; i < curWavesInfo.size(); ++i)
	{
		QMap<QString, QVariant> dict = curWavesInfo[i].toMap();
		int spawnTime = dict.value("spawnTime").toInt();
		Enemy *enemy = new Enemy(startWayPoint, this);
		m_enemyList.push_back(enemy);
		QTimer::singleShot(spawnTime, enemy, SLOT(doActivate()));
	}
	return true;
}
void MainWindow::loadTowerPositions()
{
    QFile file(":/config/TowersPosition.plist");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "TowerDefense", "Cannot Open TowersPosition.plist");
        return;
    }

    PListReader reader;
    reader.read(&file);

    QList<QVariant> array = reader.data();
    foreach (QVariant dict, array)
    {
        QMap<QString, QVariant> point = dict.toMap();
        int x = point.value("x").toInt();
        int y = point.value("y").toInt();
        m_towerPositionsList.push_back(QPoint(x, y));
    }

    file.close();
}
//界面绘制
void MainWindow::paintEvent(QPaintEvent *)
{
    if (m_gameEnded || m_gameWin)
    {   //输赢
        QString text = m_gameEnded ? "Defeat!!!" : "Victory!!!";
        QPainter painter(this);
        painter.setPen(QPen(Qt::red));
        painter.drawText(rect(), Qt::AlignCenter, text);
        return;
    }
    QPixmap cachePix(":/image/Bg.png");
    QPainter cachePainter(&cachePix);
    //界面绘制缓存
    foreach (const TowerPosition &towerPos, m_towerPositionsList)
        towerPos.draw(&cachePainter);

    foreach (const Tower *tower, m_towersList)
        tower->draw(&cachePainter);

    foreach (const WayPoint *wayPoint, m_wayPointsList)
        wayPoint->draw(&cachePainter);

    foreach (const Enemy *enemy, m_enemyList)
        enemy->draw(&cachePainter);

    foreach (const Bullet *bullet, m_bulletList)
        bullet->draw(&cachePainter);
    drawWave(&cachePainter);
    drawHP(&cachePainter);
    drawPlayerGold(&cachePainter);
    QPainter painter(this);
    painter.drawPixmap(0, 0, cachePix);
}
QList<Enemy *> MainWindow::enemyList() const
{
	return m_enemyList;
}
void MainWindow::gameStart()
{
	loadWave();
}
