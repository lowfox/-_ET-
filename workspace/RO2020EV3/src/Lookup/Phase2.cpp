#include "Phase2.h"

bool Phase2::run()
{
    // 5回ゲート通過処理
    while(m_ctrl.GetPassCount() < 5){

        // 現在距離セット   
        m_ctrl.SetStartDistance();

        // 閾値セット       
        m_ctrl.SetOffset();

        // ゲートを通過処理  

        auto tracecolor = Drive::ColorCalibrate::GetTraceColor(MIN_TARGET);

        Drive::SetDriveMode(DriveMode::LineTrace);

        Drive::LineTrace::SetTraceColor(tracecolor);
        
        Drive::LineTrace::SetPID({ 0.3f, 0.0f, 0.1f });

        if(!Drive::Drive(15))
        {
            return false;
        }
     
        while(!m_ctrl.CompareVal()){};

        if(!Drive::Stop())
        {
            return false;
        }

        // ゲート通過回数カウントアップ
        m_ctrl.UpPassCnt();

        if(m_ctrl.GetPassCount() >= 5)
        {
            return true;
        }

        if(!t_ctrl.StageAngle(MAX_TARGET))
        {
            return false;
        }
       
        RyujiEv3Engine::GetLeftMotor()->setCounts(324,30,false);
        RyujiEv3Engine::GetRightMotor()->setCounts(-324,30,true);

        if(Drive::LineTrace::GetSide() == Side::Right)
        {
            Drive::LineTrace::SetSide(Side::Left);
        }
        else{
            Drive::LineTrace::SetSide(Side::Right);
        }

        if(!Drive::Stop())
        {
            return false;
        }

        tslp_tsk(500);

        // 超音波データリセット 
        SonarFilter::GetInstance()->RestartData();

        // 超音波非同期スタート 
        SonarControl::GetInstance()->SonarRun();
        tslp_tsk(1500);

        Drive::SetDriveMode(DriveMode::LineTrace);

        tracecolor = Drive::ColorCalibrate::GetTraceColor(MAX_TARGET);

        Drive::LineTrace::SetTraceColor(tracecolor);

        Drive::LineTrace::SetPID({ 0.4f, 0.0f, 0.1f });

        // 前進指示       
        if(!Drive::Drive(15))
        {
            return false;
        }

        // 閾値が見つかるまで無限ループ
        while(1){
            if(SonarControl::GetInstance()->CheckAvg()){
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
    }

    return true;
}