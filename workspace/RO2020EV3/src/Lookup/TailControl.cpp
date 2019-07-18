#include "TailControl.h"
#include <stdexcept>
bool TailControl::Angle(int32 target_val)
{
    if(!RyujiEv3Engine::GetTailMotor()->setCounts(target_val,30,true))
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
    RyujiEv3Engine::GetTailMotor()->setCounts(-5,1,true);
    tslp_tsk(250);
    diff_val = RyujiEv3Engine::GetTailMotor()->getCounts();
    diff_val = 75 - diff_val;

    if(diff_val >= 2){
    diff_val += 1;
    }

    RyujiEv3Engine::GetTailMotor()->setCounts(-9 + diff_val,1,true);
    tslp_tsk(250);
    diff_val = RyujiEv3Engine::GetTailMotor()->getCounts();
    diff_val = 66 - diff_val;

    if(diff_val >= 3 ){
    diff_val += 2;
    }

    RyujiEv3Engine::GetTailMotor()->setCounts(-13 + diff_val,1,true);
    tslp_tsk(500);
    return true;
    }
    
    // Phase2中に態勢を戻すとき使用する。
    else if(target_val == MAX_TARGET)
    {
    diff_val = (66-diff_val);
    Drive::SetDriveMode(DriveMode::Nomal);
    Drive::Drive(-90,0);
    while(Steering::GetDistance() - now_dist > -10 ){}
    RyujiEv3Engine::GetTailMotor()->setCounts(diff_val,100,true);
    Drive::Stop();
    tslp_tsk(1000);

    now_dist = Steering::GetDistance();
    diff_val = RyujiEv3Engine::GetTailMotor()->getCounts();
    diff_val = (71-diff_val);
    Drive::Drive(-50,0);
    while(Steering::GetDistance() - now_dist > -10 ){}
    RyujiEv3Engine::GetTailMotor()->setCounts(diff_val,100,true);
    Drive::Stop();
    tslp_tsk(1000);
  
    now_dist = Steering::GetDistance();
    diff_val = RyujiEv3Engine::GetTailMotor()->getCounts();
    diff_val = (80-diff_val);
    if(diff_val <= 2){
        return true;
    }
    Drive::Drive(-5,0);
    while(Steering::GetDistance() - now_dist > -10 ){}
    RyujiEv3Engine::GetTailMotor()->setCounts(diff_val,20,true);
    Drive::Stop();
    tslp_tsk(1000);
    return true;
    }
    return false;
}
