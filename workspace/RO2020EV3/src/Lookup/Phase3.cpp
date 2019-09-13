#include "Phase3.h"

bool Phase3::run()
{
    if(!t_ctrl.StageAngle(MAX_TARGET))
    {
        return false;
    }
    
    //　ラインチェック 
    if(e_ctrl.LineCheck()){
        return true;
    }

    // カラーセンサースレッド開始 
    e_ctrl.StartColor();
    
    // 左ラインチェック 
    if(e_ctrl.LeftTurn()){
        return true;
    }

    //　元の位置に戻る処理
    if(!RyujiEv3Engine::GetLeftMotor()->setCounts(108,1,false)){
        return false;
    }

    if(!RyujiEv3Engine::GetRightMotor()->setCounts(-108,1,true))
    {
        return false;
    }

    // 右ラインチェック 
    if(e_ctrl.RightTurn()){
        return true;
    }

    // 出来なかった場合は元の位置に戻す
    if(!RyujiEv3Engine::GetLeftMotor()->setCounts(-108,1,false)){
        return false;
    }

    if(!RyujiEv3Engine::GetRightMotor()->setCounts(108,1,true))
    {
        return false;
    }

    return true;
}