#include"seesawClimber.h"

bool seesawClimber::run(void){
    EV3_LOG("seesawClimber__start\n");

    wheelAligner i_wheelAligner;
    wheelClimber i_wheelClimber;
    distanceRunner i_distanceRunner;
    tailPositioner i_tailPositioner;
    getUp i_getUp;
    braker i_braker;
    straightRunner i_straightRunner;

/*
    if(!i_getUp.run(&m_alignTail,-3.0)){return false;}
    if(!i_braker.run()){return false;}
    dly_tsk(600);
   // while(1){}
    if(!i_wheelAligner.run()){return false;}
 */
    if(!i_wheelClimber.run()){return false;}
    
    if(!i_distanceRunner.run(&m_postRun)){return false;}
 
    //K”öæ‚èã‚°
    if(!i_getUp.run(&m_bodyClimbTail3,m_runUpDistance)){return false;}
    //if(!i_straightRunner.run(60)){return false;}
    if(!i_tailPositioner.run(&m_tailClimbTail)){return false;}
    if(!i_distanceRunner.run(&m_tailClimbPostRun1)){return false;}
    if(!i_distanceRunner.run(&m_tailClimbPostRun2)){return false;}

    if(!RyujiEv3Engine::GetTailMotor()->stop(true)){
        return false;
    }
    //if(!Drive::Stop()){return false;}
    
   if(!i_braker.run()){return false;}
   //if(!i_distanceRunner.run(&m_finulRun)){return false;}
    dly_tsk(1500);
    return true;
}