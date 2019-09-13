#include"getUp.h"

bool getUp::run(InfoTail* info,float backDistance){
    EV3_LOG("getUp__start\n");
    if(info==NULL){return false;}
    distanceRunner i_distanceRunner;
    tailPositioner i_tailPositioner;
    m_getUpRun.distance=backDistance;
    if(!i_distanceRunner.run(&m_getUpRun)){return false;}
    if(!i_tailPositioner.run(info)){return false;}
    EV3_LOG("getUp__finish\n");
    return true;
}