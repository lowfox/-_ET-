#include"garageInit.h"

bool garageInit::run(void){
    getUp i_getUp;
    braker i_braker;
    distanceRunner i_distanceRunner;
    int nowCounts;

    //?¿½Å‘ï¿½55?¿½x
    nowCounts = RyujiEv3Engine::GetTailMotor()->getCounts();
    while(nowCounts<75){
        
        m_lineTraseTail1.angle = nowCounts+6;
        if(!i_getUp.run(&m_lineTraseTail1,m_runUpDistance1)){return false;}
        if(!i_braker.run()){return false;}
        dly_tsk(700);
        
        if(!i_distanceRunner.run(&m_safeRun1)){return false;}
        nowCounts = RyujiEv3Engine::GetTailMotor()->getCounts();
    }
    RyujiEv3Engine::GetSpeaker()->playTone(300,100);    

    if(!i_getUp.run(&m_lineTraseTail4,m_runUpDistance3)){return false;}
    if(!i_braker.run()){return false;}
    
    RyujiEv3Engine::GetSpeaker()->playTone(500,300);
    dly_tsk(600);

    if(!RyujiEv3Engine::GetLeftMotor()->stop(true)){return false;}
    if(!RyujiEv3Engine::GetRightMotor()->setPWM(m_lineReturnPwm)){return false;}
    dly_tsk(m_lineReturnTime);

    if(!RyujiEv3Engine::GetRightMotor()->stop(true)){return false;}
    if(!RyujiEv3Engine::GetLeftMotor()->stop(true)){return false;}
    
    if(!m_garageInitlineTracer.run(m_lineReturnPwm,m_garageInitAngle)){return false;}
    
    m_firstDistance=Steering::GetDistance();

    while(Steering::GetDistance() - m_firstDistance < m_lineReturnDistance){}
    
    if(!i_braker.run()){return false;}
    if(!RyujiEv3Engine::GetRightMotor()->stop(true)){return false;}
    if(!RyujiEv3Engine::GetLeftMotor()->stop(true)){return false;}
    
    RyujiEv3Engine::GetSpeaker()->playTone(800,2000);
    dly_tsk(1000);


    return true;
}