#include "defetowerparent.h"
//子弹
void DefeTowerParent::BulletMove()         //子弹移动函数
{
    //子弹移动
    for(auto bulli : BulletVec)
    {
        const int speed = 20;
        //子弹移动速度，每一次刷新画面移动的像素距离
        //子弹的移动方向为左则子弹x坐标每次-=，反之+=
        bulli->dirflag ? bulli->coor.x -= speed : bulli->coor.x += speed;
        //子弹纵坐标改变
        bulli->coor.y = bulli->k * bulli->coor.x + bulli->b;
    }
    //遍历删除越界子弹
    for(auto bullit = BulletVec.begin(); bullit != BulletVec.end(); bullit++)
        if((*bullit)->coor.x > 1040 || (*bullit)->coor.x < 0 || (*bullit)->coor.y > 640 || (*bullit)->coor.y < 0)
        {
            delete bullit;
            BulletVec.erase(bullit);
            break;
        }
}
void DefeTowerParent::InterBullet()     //新建子弹函数
{
    counter++;

    if(counter < 7 || !aimsmon)      //计数器到达一定数值且目标怪物不为空时
    return;

    //向子弹数组中插入子弹
    BulletStr *bull = new BulletStr(CoorStr(UpLeftX + 40, UpLeftY + 40));

    bull->coor.x = UpLeftX + 40, bull->coor.y = UpLeftY + 40;

    //计算每一个子弹的路径
    if((!(aimsmon->GetX() - bull->coor.x)))   //除数为0或时不创建子弹
    {
        delete bull;
        bull = NULL;
        goto L1;
    }

    bull->k = (aimsmon->GetY() - bull->coor.y) / (aimsmon->GetX() - bull->coor.x);
    bull->b = aimsmon->GetY() - aimsmon->GetX() * bull->k;

    bull->coor.x = UpLeftX + 40, bull->coor.y = UpLeftY + 40;

    BulletVec.push_back(bull);              //将子弹插入到子弹数组当中

    if(aimsmon->GetX() <= UpLeftX + 40)     //确定子弹的移动方向
        bull->dirflag = true;
    L1:

    counter = 0;    //计数器重置为0

}

int DefeTowerParent::GetBulletWidth()//获取子弹的宽度
{
    return bullwidth;
}

int DefeTowerParent::GetBulletHeight()//获取子弹的宽度
{
    return bullheight;
}

int DefeTowerParent::GetAttack()//获取防御塔攻击力
{
    return attack;
}

int DefeTowerParent::GetExplRangeHeight()//获取爆炸效果高
{
    return ExplRangeHeight;
}

void DefeTowerParent::SetExplRangeWidthHeight(int width, int height)   //设置防御塔对应的爆炸效果的宽高
{
    ExplRangeWidth = width, ExplRangeHeight = height;
}

void DefeTowerParent::SetBulletWidthHeight(int width, int height)      //设置子弹宽高
{
    bullwidth = width, bullheight = height;
}



