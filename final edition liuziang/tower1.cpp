#include "tower1.h"
//tower1
//构造
tower1::tower1(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    //初始化成员变量，这里不能用初始化列表
    mx = x, my = y;
    BaseImgPath = QString(":/image/tower1base.png");
    DefImgPath = QString(":/image/tower1.png");
    //宽高 左上角的坐标
    width = Fwidth, height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;
    Range = 200;    //射程
    BullPath = QString(":/image/Shells0.png");//子弹模型
    bullwidth = 30, bullheight = 30;          //子弹大小
    attack = 40;    //攻击力
    ExplRangeWidth = 65;    //爆炸效果宽高
    ExplRangeHeight = ExplRangeWidth;//圆斑型爆炸
}
