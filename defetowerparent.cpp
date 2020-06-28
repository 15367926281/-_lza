#include "defetowerparent.h"
//防御塔的父类
int DefeTowerParent::GetX()    //获取横坐标
{
    return mx;
}
int DefeTowerParent::GetY()      //获取横坐标
{
    return my;
}
int DefeTowerParent::GetWidth()  //获取宽
{
    return width;
}
int DefeTowerParent::GetHeight()  //获取高
{
    return height;
}
int DefeTowerParent::GetRotatAngle()//获取旋转角度
{
    return RotatAngle;
}
QString DefeTowerParent::GetBaseImgPath() //获取底座图片路径
{
    return BaseImgPath;
}
QString DefeTowerParent::GetDefImgPath()//获取防御塔图片路径
{
    return DefImgPath;
}
int DefeTowerParent::GetUpLeftX() //获取防御塔左上角原横坐标
{
    return UpLeftX;
}
int DefeTowerParent::GetUpLeftY()//获取防御塔左上角原纵坐标
{
    return UpLeftY;
}
void DefeTowerParent::SetRotatAngle(int rot)    //设置旋转角度
{
    RotatAngle = rot;
}
int DefeTowerParent::GetRange()           //获取防御塔射程
{
    return Range;
}
Monster* DefeTowerParent::GetAimsMonster()//返回当前防御塔的目标怪物
{
    return aimsmon;
}
void DefeTowerParent::SetAimsMonster(Monster* mon)  //设置当前防御塔的目标怪物
{
    aimsmon = mon;
}
QString DefeTowerParent::GetBulletPath()  //返回防御塔子弹图片路径
{
    return BullPath;
}
QVector<BulletStr*>& DefeTowerParent::GetBulletVec()//返回子弹数组
{
    return BulletVec;
}
//升级变化
void DefeTowerParent::SetAttack(int attack) //设置防御塔攻击力
{
    this->attack = attack;
}

void DefeTowerParent::SetWidthHeight(int width, int height)  //设置防御塔宽高
{
    this->width = width, this->height = height;
}

void DefeTowerParent::SetXY(int x, int y)       //设置坐标
{
    this->mx = x, this->my = y;
}

int& DefeTowerParent::SetRange()                //设置防御塔的攻击范围
{
    return Range;
}

int DefeTowerParent::GetExplRangeWidth()//获取爆炸效果宽
{
    return ExplRangeWidth;
}

