#include"gotoSeesaw.h"


bool gotoSeesaw::run(void){
    modeSwitcher i_modeSwitcher;
    braker i_braker;
    angularVelocityDetector i_angularVelocityDetector;
    lineTracer i_lineTracer;
    tailPositioner i_tailPositioner;

    //スタートから灰色検知ま
    /*
    EV3_LOG("testRun__Start\n");
    RyujiEv3Engine::GetGyroSensor()->setOffset(0);
    EV3_LOG("testRun__setOffset__OK\n");
    if(!Steering::SetMode(SteeringMode::Balance)){
        EV3_LOG_ERROR("testRun////setMode()_False\n");
        return false;}
    EV3_LOG("testRun__setMode__OK\n");
    

    //float pid[3]={2.0f,0f,0f};
    //Drive::LineTrace::SetPID(pid);
    //Drive::SetDriveMode(DriveMode::Nomal);
    distanceRunner i_distanceRunner;
    InfoDistanceRun testRun={5,50.0f};
    if(!i_distanceRunner.run(&testRun)){
        EV3_LOG_ERROR("testRun////distansRunner.run()_false\n");
        return false;
    }
    */
   
   

    EV3_LOG("gotoSeesaw__Start\n");


    if(!i_modeSwitcher.run()){return false;}
    if(!i_braker.run()){return false;}
    seesawGlobal::cntValue10ms=0;
    /*
    ev3_sta_cyc(CNT_TEN_MS);
    while(seesawGlobal::cntValue10ms<100){
        EV3_LOG("sleep...");
    };//1秒間スリープ
    ev3_stp_cyc(CNT_TEN_MS);
    */
    dly_tsk(1000);
    if(!RyujiEv3Engine::GetGyroSensor()->reset()){return false;}
    RyujiEv3Engine::GetGyroSensor()->setOffset(0);
    //if(!i_angularVelocityDetector.setOffsetValue(m_seesawDetectValue)){return false;}
    if(!i_lineTracer.run(m_pwm)){return false;}
    //while(!i_angularVelocityDetector.detect()){}
    seesawGlobal::cntValue10ms=0;
    /*
    ev3_sta_cyc(CNT_TEN_MS);
    while(seesawGlobal::cntValue10ms<150){
        EV3_LOG("sleep...");
    };//1.5秒間スリープ
    ev3_stp_cyc(CNT_TEN_MS);
    */
    dly_tsk(1500);
    ev3_sta_cyc(GOTO_GET_DISTANCE);
    seesawGlobal::gotoLastDistance=Steering::GetDistance();
    do{
         m_gotoPeriodDistance = seesawGlobal::gotoNowDistance - seesawGlobal::gotoLastDistance;//660ms毎にalign,lastを更新
        EV3_LOG("GOTO!:get_distance__NowDistance=%f, lastdistance=%f ,",seesawGlobal::gotoNowDistance,seesawGlobal::gotoLastDistance);              
        EV3_LOG("GOTO!:periodDistance=%f\n", m_gotoPeriodDistance);
    }while( m_gotoPeriodDistance > m_detectDistance ||  m_gotoPeriodDistance < 0 );//500ms
    
    if(!i_braker.run()){return false;}
    
    ev3_stp_cyc(GOTO_GET_DISTANCE);

    EV3_LOG("gotoSeesaw__finesh\n");
    RyujiEv3Engine::GetLED()->setColor(LED_Color::RED);
    //while(1){}
    
    return true;
    

   
}

void cnt_ten_ms(intptr_t exinf){
    seesawGlobal::cntValue10ms++;
    EV3_LOG("10msCNT=%d\n",seesawGlobal::cntValue10ms);
}

void goto_get_distance(intptr_t exinf){
    seesawGlobal::gotoLastDistance = seesawGlobal::gotoNowDistance;
    seesawGlobal::gotoNowDistance =  Steering::GetDistance();
    EV3_LOG("4ms!!__get_distance!!!");
}