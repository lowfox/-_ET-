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
        if(!m_ctrl.CompareVal())
        {
            return false;
        }

        // ゲート通過回数カウントアップ
        m_ctrl.UpPassCnt();

        if(m_ctrl.GetPassCount() >= 5){
            break;
        }

         if(!Drive::Rotate())
         {
             return false;
         }
        // テスト用コード「Drive::Stopまで」(後でRotate()に変更)
        //RyujiEv3Engine::GetLeftMotor()->setCounts(324,30,false);
        //RyujiEv3Engine::GetRightMotor()->setCounts(-324,30,true);

        if(!Drive::Stop())
        {
            return false;
        }
        tslp_tsk(500);

        if(!t_ctrl.StageAngle(MAX_TARGET))
        {
            return false;
        }

        // 超音波データリセット 
        SonarFilter::GetInstance()->RestartData();
        // 超音波非同期スタート 
        SonarControl::GetInstance()->SonarRun();


        auto tracecolor=Drive::ColorCalibrate::GetTraceColor(MAX_TARGET);
        Drive::LineTrace::SetTraceColor(tracecolor);
        Drive::SetDriveMode(DriveMode::LineTrace);
        // (テスト用後で上のコード追加)    

        // 前進指示       
        if(!Drive::Drive(5))
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