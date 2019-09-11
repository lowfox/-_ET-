#include"seesawDesc.h"

bool seesawDesc::run(void){
    braker i_braker;
    angleDetector i_angleDetector;
    getUp i_getUp;
        m_initState=1;
    straightRunner i_straightRunner;
    angularVelocityDetector i_angularvelocityDetector;
    tailPositioner i_tailPositioner;
     distanceRunner i_distanceRunner;
     RyujiEv3Engine::GetLED()->setColor(LED_Color::OFF);
    //初期状態を把握。
    if(!i_braker.run()){return false;}
    /*
    if(!i_angleDetector.setTargetValue(m_onSeesawTargetValue)){return false;}
    if(i_angleDetector.detect()){
        m_initState=1;// シーソー上に車体がある
    }else{
        if(!i_angleDetector.setTargetValue(m_wheelDescTargetValue)){return false;}
        if(i_angleDetector.detect()){
            m_initState=2;//タイヤのみ降りている
        }else
        {
            if(!i_angleDetector.setTargetValue(m_bodyDescTargetValue)){return false;}
            if(i_angleDetector.detect()){
                m_initState=3;//車体がシーそー下にある
            }else{
                return false;
            }
        }
        
    }
    */


    if(!i_distanceRunner.run(&m_preRun)){return false;}
    if(!i_tailPositioner.run(&m_descTail)){return false;}
    dly_tsk(600);
    RyujiEv3Engine::GetGyroSensor()->setOffset(0);
    if(!i_angularvelocityDetector.setOffsetValue(m_wheelDescOffset)){return false;}
  
    if(!i_straightRunner.run(m_wheelDescPwm)){return false;}
    while(!i_angularvelocityDetector.detect()){}
    if(!RyujiEv3Engine::GetSpeaker()->playTone(500,100)){
        EV3_LOG("ERROR:playTone();");
        return false;}
    RyujiEv3Engine::GetLED()->setColor(LED_Color::GREEN);
    EV3_LOG("WHEEL DESC!");//スピーカー鳴らす

    if(!i_distanceRunner.run(&m_wheelAfterRun)){return false;}
    if(!i_braker.run()){return false;}
    dly_tsk(300);
    RyujiEv3Engine::GetLED()->setColor(LED_Color::OFF);
   
    if(!i_tailPositioner.run(&m_tailDescTail)){return false;}
    // if(!i_distanceRunner.run(&m_tailDescRun)){return false;}
   /*
    if(!i_straightRunner.run(m_tailDescPwm)){return false;}
    if(!i_angularvelocityDetector.setOffsetValue(m_tailDescOffset)){return false;}
    while(!i_angularvelocityDetector.detect()){}
   */ 
    if(!i_distanceRunner.run(&m_tailDescRun)){return false;}
    EV3_LOG("TAIL DESC!");
    if(!RyujiEv3Engine::GetSpeaker()->playTone(400,50)){
        EV3_LOG("ERROR:playTone();");
        return false;}
    
    RyujiEv3Engine::GetLED()->setColor(LED_Color::GREEN);
    //if(!i_braker.run()){return false;}
    //dly_tsk(1000);
    //if(!i_distanceRunner.run(&m_safeStopRun)){return false;}
    if(!i_braker.run()){return false;}

    return true;
}