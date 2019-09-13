#pragma once
#include"angleDetector.h"
#include<Logger.h>

class angleDetectorTest{
    public:
    bool setTargetValueTest();
    bool detectTest();
};

struct CaseAngleDetector{
    int16 targetValue;
    bool retValue;
};
