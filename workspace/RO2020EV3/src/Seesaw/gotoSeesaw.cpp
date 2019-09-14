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
 
    dly_tsk(700);
    if(!RyujiEv3Engine::GetGyroSensor()->reset()){return false;}
    RyujiEv3Engine::GetGyroSensor()->setOffset(0);
    //if(!i_angularVelocityDetector.setOffsetValue(m_seesawDetectValue)){return false;}

    //ライン復帰処理
    if(!RyujiEv3Engine::GetRightMotor()->setPWM(5)){return false;}
    if(!RyujiEv3Engine::GetLeftMotor()->stop(true)){return false;}
    dly_tsk(m_lineReturnTime);
    if(!RyujiEv3Engine::GetRightMotor()->stop(true));

    if(!i_lineTracer.run(m_pwm,m_initAngle)){return false;}
    //while(!i_angularVelocityDetector.detect()){}

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
    
    return true;
    

   
}


void goto_get_distance(intptr_t exinf){
    seesawGlobal::gotoLastDistance = seesawGlobal::gotoNowDistance;
    seesawGlobal::gotoNowDistance =  Steering::GetDistance();
    EV3_LOG("4ms!!__get_distance!!!");
}