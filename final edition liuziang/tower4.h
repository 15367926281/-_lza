#ifndef tower4_H
#define tower4_H

#include "defetowerparent.h"

//t4防御塔
class tower4 : public DefeTowerParent
{
protected:

public:
    tower4(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth = 80, int Fheight = 80);
};

#endif // tower4_H
