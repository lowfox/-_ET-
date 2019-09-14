#include "Phase1.h"
#include "../../app.h"
#include "../Logger/CLogger.h"

bool Phase1::run()
{
    EV3_LOG_INFO("DriveStart");
    //RyujiEv3Engine::GetTailMotor()->setCounts(-80,30,true);

    //あそびをなくす
    RyujiEv3Engine::GetTailMotor()->setCounts(-15,30,false);
    tslp_tsk(1000);
    RyujiEv3Engine::GetTailMotor()->resetCounts();

    // Sideの検知
    if(Drive::LineTrace::GetSide() == Side::Left)
    {
        Drive::LineTrace::SetSide(Side::Left);
    }
    else{
        Drive::LineTrace::SetSide(Side::Right);
    }

    // bluelinemode
    Drive::LineTrace::SetLineMode(BlueLineMode::Blue);
    
    // 走行体brakemodeに変更�?示 
    if(!RyujiEv3Engine::GetLeftMotor()->stop(true))
    {
        return false;
    }   

    if(!RyujiEv3Engine::GetRightMotor()->stop(true))
    {
        return false;
    }   

    if(!RyujiEv3Engine::GetTailMotor()->stop(true))
    {
        return false;
    }   

    if(!t_ctrl.Angle(MAX_TARGET))
    {
        return false;
    }  
    
    if(!Steering::SetMode(SteeringMode::Nomal))
    {
        EV3_LOG_ERROR("Steering::setmode normal\n");
    }

    float oneDistance = Steering::GetDistance();
    if(!Drive::Drive(3)){return false;}
    while((Steering::GetDistance() - oneDistance) < 40.0f);

    if(!Drive::Stop())
    {
        return false;
    } 

    Drive::SetDriveMode(DriveMode::LineTrace);

    auto tracecolor = Drive::ColorCalibrate::GetTraceColor(MAX_TARGET);

    Drive::LineTrace::SetTraceColor(tracecolor);

    Drive::LineTrace::SetPID({ 0.3f, 0.0f, 0.1f });


    if(!Drive::Drive(15))
    {
        EV3_LOG_ERROR("DriveError");
        return false;
    }                   

    // �?音波非同期スター�?
    SonarControl::GetInstance()->SonarRun();

    // 停止位置まで比�?
    while(1){
        if(SonarControl::GetInstance()->CheckAvg())
        {
            break;
        }
    }

    if(!Drive::Stop())
    {
        return false;
    }  

    if(!t_ctrl.StageAngle(MIN_TARGET))
    {
        return false;
    } 
    
    return true;
}
