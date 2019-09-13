#include"tailPositioner.h"

bool tailPositioner::run(InfoTail* info){
    EV3_LOG("tailPositioner__start\n");
   //angle:角度:-10~200
    //speed:速度:0~100
    //blocking:bool
    if(info->angle > 200 || info->angle < -30){return false;}
    if(info->speed > 100 || info->speed < 0){return false;}
    if(info->blocking != true && info->blocking != false){return false;}
    int32 nowAngle= (RyujiEv3Engine::GetTailMotor()->getCounts());
    int32 inputAngle=(info->angle) - nowAngle;
    EV3_LOG("tailPositioner__inputAngle=%d, info->Angle=%d, nowAngle=%d\n",inputAngle,info->angle,nowAngle);
    seesawGlobal::cntValue10ms=0;
    //ev3_sta_cyc(TAIL_CNT_TEN_MS);
    if(!RyujiEv3Engine::GetTailMotor()->setCounts(inputAngle,info->speed,info->blocking)){
        return false;
    }
    if(info->blocking==false){return true;}
    //ev3_stp_cyc(TAIL_CNT_TEN_MS);

    if(!RyujiEv3Engine::GetTailMotor()->stop(true)){
        return false;
    }
    EV3_LOG("tailPositioner__finish\n");
    return true;
}

void tail_cnt_ten_ms(intptr_t exinf){
    seesawGlobal::cntValue10ms++;
    if(seesawGlobal::cntValue10ms>250){
        //尻尾タスク終了処理
    }
    EV3_LOG("10msCNT=%d\n",seesawGlobal::cntValue10ms);
}