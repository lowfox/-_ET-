#pragma once
#include"infoTail.h"
#include"braker.h"
#include"angularVelocityDetector.h"
#include"lineTracer.h"
#include"tailPositioner.h"
#include"straightRunner.h"
#include<RyujiEv3.h>
#include<Logger.h>
#include"seesawGlobal.h"
#include"distanceRunner.h"
#include<Drive.h>
#include"getUp.h"
#include<Steering.h>

enum class direction{
    forward,
    back
};
class seesawRunner{
    public:
    bool run(enum direction);
  
    private:
    int32 m_lineReturnPwm=6;
    int m_lineReturnTime=800;
    float forwardRunUpDistance=-20.0f;
    //float backRunUpDistance=-23.0f;
    InfoTail m_forwadPreTail={102,100,true};
    InfoTail m_forwardBentTail={50,90,true};
    //InfoTail m_backPreTail={48,50,true};
    InfoTail m_backBentTail={96,100,false};
    int16 m_forwardBentOffset=31;
    int16 m_backBentOffset=-30;
    int32 m_forwardPwm=3;
    int32 m_backPwm=-4;
    int m_detectCnt=4;
    int m_cnt=0;
    int m_rigidTime=150;
   // InfoDistanceRun m_postRun={5,14.0f};
  
    InfoDistanceRun m_postRunForward={23,70.0f};
    //InfoDistanceRun m_preRunForward={-10,-24.0f};
    InfoDistanceRun m_preRunBack={6,20.0f};

    float m_preDistance;
   
};


