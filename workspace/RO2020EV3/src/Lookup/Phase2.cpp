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

            TraceColor tr;
        RGB rgb = {0,0,0};
    tr = {9.6f,42.0f,rgb};

        //auto tracecolor = Drive::ColorCalibrate::GetTraceColor(MIN_TARGET);

        Drive::SetDriveMode(DriveMode::LineTrace);

        Drive::LineTrace::SetTraceColor(tr);
        
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
            if(!t_ctrl.StageAngle(MAX_TARGET))
            {
                return false;
            }
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

    tr = {7.0f,105.0f,rgb};

        Drive::SetDriveMode(DriveMode::LineTrace);

        //tracecolor = Drive::ColorCalibrate::GetTraceColor(MAX_TARGET);

        Drive::LineTrace::SetTraceColor(tr);

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