#include"lineTracer.h"
#include"straightRunner.h"

bool lineTracer::run(int32 pwm,int16 angle){
    if(pwm>100 || pwm<-100){return false;}
    
    if(!Drive::SetDriveMode(DriveMode::LineTrace)){EV3_LOG("SetDriveMode(LineTrace)....return false");}
    Drive::LineTrace::SetTraceColor(Drive::ColorCalibrate::GetTraceColor(angle));
    TraceColor traceColor;
    
    //RGB rgb={11,45,122};
    //traceColor = {5.6f,123.0f,rgb};                             //練習用

    traceColor = Drive::ColorCalibrate::GetTraceColor(angle);    //本番はこっち使う
    Drive::LineTrace::SetTraceColor(traceColor);
    Drive::LineTrace::SetPID({ 0.24f, 0.0f, 0.2f });//PIDセット
    Drive::LineTrace::SetSide(Side::Left);
    //トレースカラーがセットされてるかの確認//Takeuchi
    //セットしたはずのトレースカラー//Takeuchi
    EV3_LOG("Set Trace Color black = %f, Set Trace Color white = %f\n", traceColor.black, traceColor.white);//Takeuchi
    //実際にセットされているセットカアラー//Takeuchi
    traceColor = Drive::LineTrace::GetTraceColor();//Takeuchi(現在セットされているトレースカラーを取得)//Takeuchi
    EV3_LOG("Now Trace Color black = %f, Now Trace Color white = %f\n", traceColor.black, traceColor.white);//Takeuchi

    if(!Drive::Drive(pwm)){
        EV3_LOG("ERROR_LINETRACER_DRIVE\n");
        return false;
    }
    
  // straightRunner i_straightRunner;
  // if(!i_straightRunner.run(pwm)){return false;}
    
    return true;
}