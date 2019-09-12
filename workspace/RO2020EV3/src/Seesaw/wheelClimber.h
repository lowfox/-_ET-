#pragma once
#include<RyujiEv3.h>
#include"angleDetector.h"
#include<Drive.h>
#include<Logger.h>
#include"tailPositioner.h"
#include"infoTail.h"
#include"braker.h"
#include"straightRunner.h"
#include"angularVelocityDetector.h"
#include<Steering.h>
#include"distanceRunner.h"
#include"getUp.h"
#include"infoDistanceRun.h"
class wheelClimber{
    public:
    bool run();
    private:
    //InfoDistanceRun climbRun={50,50};

    //int16 m_rightClimbTargetValue=-100;
    //int16 m_leftClimbTargetValue=-9;
    //int16 m_wheelClimbTargetValue=-10;
    //int16 m_leftClimbOffsetValue=-56;
    //int16 m_rightClimbOffsetValue=-35;
    //int32 m_climbPwm=10;
    //int32 m_subClimbPwm=1;
    int32 m_wheelClimbPwm=15;
    //float m_getUpDistance=-5.0f;
    InfoTail m_climbTail={104,100,true};
    //InfoTail m_climbTail2={104,100,true};
    InfoTail m_climbTail_pre={102,15,true};
    float m_runUpDistance=-2.5f;
    //InfoDistanceRun m_climbDisRun={15,100.0f};
    InfoDistanceRun m_climbBeforeRun={-5,-8.0f};
};