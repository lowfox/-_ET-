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
        // 本番
        //auto tracecolor = Drive::ColorCalibrate::GetTraceColor(55);
        TraceColor traceColor;
        traceColor = {6.6f, 23.0f, 0};

        Drive::SetDriveMode(DriveMode::LineTrace);
        Drive::LineTrace::SetTraceColor(traceColor);
        Drive::LineTrace::SetPID({ 0.5f, 0.0f, 0.3f });//PID�Z�b�gTakeuchi

        //Drive::SetDriveMode(DriveMode::Nomal); //テスト用(後でLineTraceに変更)
        if(!Drive::Drive(10))
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

        if(m_ctrl.GetPassCount() >= 5){
            return true;
        }


        if(!t_ctrl.StageAngle(MAX_TARGET))
        {
            return false;
        }

        
        /*if(!Drive::Rotate())
        {
           return false;
        }
        */
       
        // テスト用コード「Drive::Stopまで」(後でRotate()に変更)
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

        //tracecolor = Drive::ColorCalibrate::GetTraceColor(MAX_TARGET);
        traceColor = {6.3f, 78.3f, 0};
        Drive::SetDriveMode(DriveMode::LineTrace);
        Drive::LineTrace::SetTraceColor(traceColor);
        
        Drive::LineTrace::SetPID({ 0.5f, 0.0f, 0.3f });//PID�Z�b�gTakeuchi
        // (テスト用後で上のコード追加)    

        // 前進指示       
        if(!Drive::Drive(10))
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