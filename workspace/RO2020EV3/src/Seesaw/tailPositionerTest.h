#pragma once
#include"infoTail.h"
#include<Logger.h>
#include"tailPositioner.h"

class tailPositionerTest{
    public:
    bool test();
};

struct CaseTailPositioner{
    InfoTail* info;
    bool retValue;
};