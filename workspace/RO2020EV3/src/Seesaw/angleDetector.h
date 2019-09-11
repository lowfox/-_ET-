#pragma once
#include<RyujiEv3.h>
#include<Logger.h>

class angleDetector{
    public:
    bool setTargetValue(int16);
    bool detect();
    #ifdef TESTMODE
        void setTestValue(int16);
    #endif

    private:
    int16 m_targetValue = 181;
    #ifdef TESTMODE
        int16 testValue;
    #endif

};