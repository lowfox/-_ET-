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
    //int16 m_rightClimbTargetValue=-17;
    //int16 m_wheelClimbTargetValue=-27;
    //int16 m_leftClimbOffsetValue=-20;
    //int16 m_rightClimbOffsetValue=-35;
    //int32 m_climbPwm=10;
    //int32 m_subClimbPwm=0;
    int32 m_wheelClimbPwm=15;
    //float m_getUpDistance=-5.0f;
    InfoTail m_climbTail={110,100,true};
    InfoTail m_climbTail_pre={107,13,true};
    float m_runUpDistance=-3.5f;
    //InfoDistanceRun m_climbDisRun={15,100.0f};
    InfoDistanceRun m_climbBeforeRun={-5,-8.0f};
};