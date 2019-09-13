#include "angularVelocityDetector.h"

bool angularVelocityDetector::setOffsetValue(int16 offset){
    
    EV3_LOG("angVelDetect__setOffset__start\n");
    if(offset > 500 || offset < -500){return false;}
    m_offsetValue=offset;
    EV3_LOG("angVelDetect__setOffset__finish\n");
    return true;
}

bool angularVelocityDetector::detect(){
    
    if(m_offsetValue > 500){return false;}
    int16 detectValue;
    #ifdef TESTMODE
        detectValue=testValue;    
    #else
        detectValue=RyujiEv3Engine::GetGyroSensor()->getRate();
        //EV3_LOG("offsetValue=%d, angVelValue=%d\n",m_offsetValue, detectValue);
    #endif
    if(m_offsetValue>0){
        if(detectValue>=m_offsetValue){
            EV3_LOG("angVelDetect__detect()__finish\n");
            return true;
        }
    }else{
        if(detectValue<=m_offsetValue){
            EV3_LOG("angVelDetect__detect()__finish\n");
            return true;
        }
    }
    return false;
}

#ifdef TESTMODE
    void angularVelocityDetector::setTestValue(int16 inputValue){
        testValue=inputValue;
    }
#endif