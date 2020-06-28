#ifndef tower1_H
#define tower1_H

#include "defetowerparent.h"

//t1继承父类
class tower1: public DefeTowerParent
{
protected:

public:
    tower1(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth = 80, int Fheight = 80);
};

#endif // tower1_H
