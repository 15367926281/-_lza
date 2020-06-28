#include "tower2.h"

//tower2
tower2::tower2(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    //初始化成员变量，这里不能用初始化列表
    mx = x, my = y;
    //地基与炮台模型
    BaseImgPath = QString(":/image/tower2base.png");
    DefImgPath = QString(":/image/tower2.png");
    width = Fwidth, height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;

    Range = 170;    //射程

    BullPath = QString(":/image/Shells1.png");
    bullwidth = 40, bullheight = 40;           //子弹大小

    attack = 65;    //攻击力

    ExplRangeWidth = 70;    //爆炸效果宽高
    ExplRangeHeight = ExplRangeWidth;
}
