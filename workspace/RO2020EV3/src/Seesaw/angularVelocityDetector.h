#pragma once
#include<RyujiEv3.h>
#include<Logger.h>
// �p���x���m�N���X
class angularVelocityDetector{
    public:
        bool setOffsetValue(int16);//臒l�ݒ�
        bool detect();//�p���x���m
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