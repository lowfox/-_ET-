#pragma once
#include"angularVelocityDetector.h"
#include<Logger.h>
class angularVelocityDetectorTest{
    public:
    bool setOffsetTest();
    bool detectTest();
};

struct CaseAngVelSetOffset{
    int16 offsetValue;
    bool retValue;
};

