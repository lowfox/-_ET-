#include "Phase1.h"
#include "../../app.h"

bool Phase1::run()
{
    // 走行体brakemodeに変更指示 
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

    auto tracecolor=Drive::ColorCalibrate::GetTraceColor(80);
    Drive::LineTrace::SetTraceColor(tracecolor);
    Drive::SetDriveMode(DriveMode::LineTrace);
    //Drive::SetDriveMode(DriveMode::Nomal); //テスト用(後でLineTraceに変更)

    if(!Drive::Drive(5,0))
    {
        return false;
    }                   

    // 超音波非同期スタート
    SonarControl::GetInstance()->SonarRun();

    // 停止位置まで比較
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
