#include"garageInit.h"

bool garageInit::run(void){
    getUp i_getUp;
    braker i_braker;
    distanceRunner i_distanceRunner;
    lineTracer i_lineTracer;
    int firstCounts;
    int secondCounts;
    int nowCounts;
    tailPositioner i_tailPositioner;

    //Å‘å55“x
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

    if(!i_getUp.run(&m_lineTraseTail3,m_runUpDistance3)){return false;}
    if(!i_braker.run()){return false;}
    
    RyujiEv3Engine::GetSpeaker()->playTone(500,300);
    dly_tsk(600);
    

    
   // if(!i_getUp.run(&m_lineTraseTail4,m_runUpDistance3)){return false;}

    RyujiEv3Engine::GetSpeaker()->playTone(600,500);

    if(!RyujiEv3Engine::GetLeftMotor()->stop(true)){return false;}
    if(!RyujiEv3Engine::GetRightMotor()->setPWM(m_lineReturnPwm)){return false;}
    dly_tsk(m_lineReturnTime);

    if(!RyujiEv3Engine::GetRightMotor()->stop(true)){return false;}
    if(!RyujiEv3Engine::GetLeftMotor()->stop(true)){return false;}
    RyujiEv3Engine::GetSpeaker()->playTone(700,500);

    if(!m_garageInitlineTracer.run(m_lineReturnPwm)){return false;}
    
    m_firstDistance=Steering::GetDistance();

    while(Steering::GetDistance() - m_firstDistance < m_lineReturnDistance){}
    
    if(!i_braker.run()){return false;}
    RyujiEv3Engine::GetSpeaker()->playTone(800,500);
    if(!i_tailPositioner.run(&m_lineTraseTail4)){return false;}
RyujiEv3Engine::GetSpeaker()->playTone(900,1000);
    return true;
}