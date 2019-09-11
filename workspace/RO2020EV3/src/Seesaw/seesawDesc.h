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
        InfoTail m_tailDescTail={60,25,false};
       
        int32 m_wheelDescPwm=1;
        int32 m_tailDescPwm=12;
        InfoDistanceRun m_wheelAfterRun={10,25.0f};
        InfoDistanceRun m_tailDescRun={20,90.0f};
        InfoDistanceRun m_safeStopRun={12,80.0f};
        InfoDistanceRun m_preRun={12,160.0f};
        InfoDistanceRun m_Run={12,150.0f};
};