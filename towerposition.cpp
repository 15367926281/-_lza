#include "towerposition.h"
//防御塔的基点位置
//构造参数列表
towerposition::towerposition(int x, int y, int width, int height)
    : mx(x), my(y), mwidth(width), mheight(height) {}
int towerposition::GetX() const     //获取横坐标
{
    return mx;
}
int towerposition::GetY() const     //获取横坐标
{
    return my;
}
int towerposition::GetWidth() const //获取宽
{
    return mwidth;
}
int towerposition::GetHeight() const //获取高
{
    return mheight;
}

