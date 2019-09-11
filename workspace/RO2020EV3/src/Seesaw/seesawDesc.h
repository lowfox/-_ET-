#pragma once
#include"braker.h"
#include"angleDetector.h"
#include"straightRunner.h"
#include"angularVelocityDetector.h"
#include"distanceRunner.h"
#include<Drive.h>
#include"infoTail.h"
#include"tailPositioner.h"
#include"getUp.h"

class seesawDesc{
    public:
        bool run(void);
    private:
        int16 m_bodyDescTargetValue=40;//int16
        int16 m_wheelDescTargetValue=100;//1ny16 
        int16 m_onSeesawTargetValue=10;//int16
        int m_initState=0;
        int16 m_wheelDescOffset=30;
        int16 m_tailDescOffset=-100;
        InfoTail m_descTail={45,30,true};
        InfoTail m_tailDescTail={60,20,false};
       
        int32 m_wheelDescPwm=1;
        int32 m_tailDescPwm=3;
        InfoDistanceRun m_wheelAfterRun={10,50.0f};
        InfoDistanceRun m_tailDescRun={10,60.0f};
        InfoDistanceRun m_safeStopRun={17,150.0f};
        InfoDistanceRun m_preRun={2,40.0f};
};