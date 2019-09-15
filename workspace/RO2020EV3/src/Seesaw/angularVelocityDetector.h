#pragma once
#include<RyujiEv3.h>
#include<Logger.h>
// 角速度検知クラス
class angularVelocityDetector{
    public:
        bool setOffsetValue(int16);//閾値設定
        bool detect();//角速度検知
        #ifdef TESTMODE
            void setTestValue(int16);
        #endif
    private:
        int16 m_offsetValue=501;
        int m_detectCnt;
        #ifdef TESTMODE
            int16 testValue;
        #endif
};