#include"wheelAligner.h"

bool wheelAligner::run(){
    EV3_LOG("wheelAligner__start\n");
    RyujiEv3Engine::GetLED()->setColor(LED_Color::RED);
    straightRunner i_straightRunner;
    braker i_braker;

    if(!i_straightRunner.run(m_alignPwm)){return false;}
    ev3_sta_cyc(GET_DISTANCE);
    seesawGlobal::lastDistance=Steering::GetDistance();
    EV3_LOG("lastDistance=%f\n",seesawGlobal::lastDistance);
    do{
        m_periodDistance = seesawGlobal::alignDistance - seesawGlobal::lastDistance;//660ms–ˆ‚Éalign,last‚ðXV
        EV3_LOG("get_distance__alignDistance=%f, lastdistance=%f ,",seesawGlobal::alignDistance,seesawGlobal::lastDistance);              
        EV3_LOG("periodDistance=%f\n",m_periodDistance);
    }while(m_periodDistance > m_detectDistance || m_periodDistance < 0 );
    if(!i_braker.run()){return false;}
    EV3_LOG("wheelAligner.run() ... align finish!\n");
    ev3_stp_cyc(GET_DISTANCE);
    RyujiEv3Engine::GetLED()->setColor(LED_Color::OFF);
    while(1){}
    return true;
}

void get_distance(intptr_t exinf){
    seesawGlobal::lastDistance = seesawGlobal::alignDistance;
    seesawGlobal::alignDistance =  Steering::GetDistance();
    EV3_LOG("4ms!!__get_distance!!!");
}