#include "TailControl.h"
#include <stdexcept>
bool TailControl::Angle(int32 target_val,int32 speed)
{
    if(!RyujiEv3Engine::GetTailMotor()->setCounts(target_val,speed,true))
    {
        return false;
    }
    return true;
}

bool TailControl::StageAngle(int32 target_val)
{

    auto diff_val = RyujiEv3Engine::GetTailMotor()->getCounts();//目的角度の差
    auto now_dist = Steering::GetDistance();//今までモーターの回転数

    if(target_val == MIN_TARGET)
    {
    if(!RyujiEv3Engine::GetTailMotor()->setCounts(-5,1,true)){
        return false;
    }

    tslp_tsk(250);
    diff_val = RyujiEv3Engine::GetTailMotor()->getCounts();
    diff_val = 75 - diff_val;

    if(diff_val >= ANGLE_ADJUST_1){
    diff_val += ANGLE_ADJUST_VAL_1;
    }

    if(!RyujiEv3Engine::GetTailMotor()->setCounts(-9 + diff_val,1,true)){
        return false;
    }

    tslp_tsk(250);
    diff_val = RyujiEv3Engine::GetTailMotor()->getCounts();
    diff_val = 66 - diff_val;

    if(diff_val >= ANGLE_ADJUST_2 ){
    diff_val += ANGLE_ADJUST_VAL_2;
    }

    if(!RyujiEv3Engine::GetTailMotor()->setCounts(-13 + diff_val,1,true)){
        return false;
    }

    tslp_tsk(500);
    return true;
    }
    
    // Phase2中に態勢を戻すとき使用する。
    else if(target_val == MAX_TARGET)
    {
    diff_val = (66-diff_val);
    Drive::SetDriveMode(DriveMode::Nomal);

    if(!Drive::Drive(-90)){
        return false;
    }

    while(Steering::GetDistance() - now_dist > -10 ){}
    if(!RyujiEv3Engine::GetTailMotor()->setCounts(diff_val,100,true)){
        return false;
    }

    Drive::Stop();
    tslp_tsk(1000);

    now_dist = Steering::GetDistance();
    diff_val = RyujiEv3Engine::GetTailMotor()->getCounts();
    diff_val = (71-diff_val);
    
    if(!Drive::Drive(-50)){
        return false;
    }

    while(Steering::GetDistance() - now_dist > -10 ){}

    if(!RyujiEv3Engine::GetTailMotor()->setCounts(diff_val,100,true)){
        return false;
    }

    Drive::Stop();
    tslp_tsk(1000);
  
    now_dist = Steering::GetDistance();
    diff_val = RyujiEv3Engine::GetTailMotor()->getCounts();
    diff_val = (80-diff_val);
    if(diff_val <= MAX_TARGET_BOUNDARY){
        return true;
    }
    
    if(!Drive::Drive(-5)){
        return false;
    }

    while(Steering::GetDistance() - now_dist > -10 ){}
    if(!RyujiEv3Engine::GetTailMotor()->setCounts(diff_val,20,true)){
        return false;
    }

    Drive::Stop();
    tslp_tsk(1000);
    return true;
    }
    return false;
}
