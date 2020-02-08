#pragma once
#include<RyujiEv3.h>
#include"lineTracer.h"
#include<Logger.h>

class lineTracerTest{
    public:
    bool test();
};

struct CaseLineTracer{
    int32 pwm;
    bool retValue;
};