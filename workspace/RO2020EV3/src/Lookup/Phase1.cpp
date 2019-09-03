#include "Phase1.h"
#include "../../app.h"
#include "../Logger/CLogger.h"

bool Phase1::run()
{
    EV3_LOG_INFO("DriveStart");
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
 
  TraceColor traceColor;
  //RGB rgb = {0, 0, 0};
  traceColor = {6.3f, 78.3f, 0};  //練習用
  // 本番
	//auto tracecolor = Drive::ColorCalibrate::GetTraceColor(MAX_TARGET);
    Drive::SetDriveMode(DriveMode::LineTrace);
    Drive::LineTrace::SetTraceColor(traceColor);
    Drive::LineTrace::SetPID({ 0.5f, 0.0f, 0.3f });
    //Drive::SetDriveMode(DriveMode::Nomal); //テスト用(後でLineTraceに変更)

    if(!Drive::Drive(5))
    {
        EV3_LOG_ERROR("DriveError");
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
