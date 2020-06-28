#include "tower3.h"

//tower3
tower3::tower3(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    //初始化成员变量，这里不能用初始化列表
    mx = x, my = y;
    BaseImgPath = QString(":/image/tower1base.png");
    DefImgPath = QString(":/image/tower3.png");
    width = Fwidth, height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;

    Range = 260;    //射程

    BullPath = QString(":/image/Shells2.png");
    bullwidth = 40, bullheight = 40;           //子弹大小

    attack = 94;    //攻击

    ExplRangeWidth = 75;    //爆炸效果宽高
    ExplRangeHeight = ExplRangeWidth;
}
