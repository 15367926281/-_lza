#include "tower4.h"

//tower4
//构造
tower4::tower4(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    //初始化成员变量，这里不能用初始化列表
    mx = x, my = y;
    BaseImgPath = QString(":/image/tower2base.png");
    DefImgPath = QString(":/image/tower4.png");
    width = Fwidth, height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;

    BullPath = QString(":/image/Shells3.png");

    bullwidth = 40, bullheight = 40; //子弹大小
    attack = 118;                    //攻击力
    Range = 230;                     //射程
    ExplRangeWidth = 85;             //爆炸效果宽高
    ExplRangeHeight = ExplRangeWidth;
}
