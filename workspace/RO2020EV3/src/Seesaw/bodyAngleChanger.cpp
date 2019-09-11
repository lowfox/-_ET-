#include"bodyAngleChanger.h"

bool bodyAngleChanger::run(InfoTail* info){
    EV3_LOG("bodyAngleChanger__start\n");
    if(info==NULL){
        EV3_LOG_ERROR("bodyAngleChanger__info is NULL\n");
        return false;}
    getUp i_getUp;
    tailPositioner i_tailPositioner;
    braker i_braker;
    
    m_nowAngle=RyujiEv3Engine::GetTailMotor()->getCounts();
    if(m_nowAngle==info->angle){
        EV3_LOG("bodyAngleChanger__nowAngle==info->angle\n");
        return true;
    }else if(m_nowAngle < info->angle){
        if(!i_getUp.run(info,-40.0f)){return false;}
    }else{
        if(!i_tailPositioner.run(info)){return false;}
    }
    if(!i_braker.run()){return false;}
    EV3_LOG("bodyAngleChanger__finish\n");
    return true;
}