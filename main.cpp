#include "mainwindow.h"
#include "startfrom.h"      //初始画面
#include <QApplication>
#include <QMediaPlayer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartFrom w;
    w.show();
    QMediaPlayer* player = new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/86153/Desktop/Defence/ground_music.mp3"));
    player->setVolume(100);
    player->play();
    return a.exec();
}
