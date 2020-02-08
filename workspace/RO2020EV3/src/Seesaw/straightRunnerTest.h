#pragma once
#include<RyujiEv3.h>
#include"straightRunner.h"
#include<Logger.h>
class straightRunnerTest{
    public:
    bool test();
};

struct CaseStraightRunnerTest
{
    int32 pwm;
    bool retValue;
    /* data */
};
