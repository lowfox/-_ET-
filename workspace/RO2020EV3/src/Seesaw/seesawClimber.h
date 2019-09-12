#pragma once
#include "bodyAngleChanger.h"
#include"wheelAligner.h"
#include"wheelClimber.h"
#include"distanceRunner.h"
#include"getUp.h"
#include"tailPositioner.h"
#include"braker.h"
#include"infoTail.h"
#include<Drive.h>
#include "infoDistanceRun.h"

class seesawClimber{
    public:
        bool run(void);
    private:
       // InfoTail m_initTail={85,100,true};//最初の昇段突入角度
        //InfoTail m_bodyClimbTail={101,80,true};//車体乗り上げのため
       // InfoTail m_bodyClimbTail2={103,50,true};//車体乗り上げのため
        InfoTail m_bodyClimbTail3={129,19,true};//車体乗り上げのため
        InfoTail m_tailClimbTail={107,100,false};//車体乗り上げ後、尻尾乗り上げのため
        InfoTail m_alignTail={98,15,true};
        //InfoDistanceRun m_postRun3={-7,-25.0f};//少しバック

       // InfoDistanceRun m_postRun2={10,30.0f};//両輪乗り上げ後、尻尾を淵につけるため
        //InfoDistanceRun m_tailClimbRun={30,65.0f};
        //InfoDistanceRun m_tailClimbPreRun={40,80.0f};
         InfoDistanceRun m_postRun={15,105.0f};//この終わりに尻尾が持ち上がる
        InfoDistanceRun m_tailClimbPostRun1={30,130.0f};
        InfoDistanceRun m_tailClimbPostRun2={13,70.0f};
        float m_runUpDistance=-5.0f;
        //InfoDistanceRun m_finulRun={-3,-10.0f};
        // m_preRun2={5,30};//両輪乗り上げ後、尻尾を淵につけるため
        
};