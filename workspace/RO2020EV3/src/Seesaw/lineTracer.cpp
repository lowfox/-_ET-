#include"lineTracer.h"
#include"straightRunner.h"

bool lineTracer::run(int32 pwm,int16 angle){
    if(pwm>100 || pwm<-100){return false;}
    
    if(!Drive::SetDriveMode(DriveMode::LineTrace)){EV3_LOG("SetDriveMode(LineTrace)....return false");}
    Drive::LineTrace::SetTraceColor(Drive::ColorCalibrate::GetTraceColor(angle));
    TraceColor traceColor;
    
    //RGB rgb={11,45,122};
    //traceColor = {5.6f,123.0f,rgb};                             //���K�p

    traceColor = Drive::ColorCalibrate::GetTraceColor(angle);    //�{�Ԃ͂������g��
    Drive::LineTrace::SetTraceColor(traceColor);
    Drive::LineTrace::SetPID({ 0.24f, 0.0f, 0.2f });//PID�Z�b�g
    Drive::LineTrace::SetSide(Side::Left);
    //�g���[�X�J���[���Z�b�g����Ă邩�̊m�F//Takeuchi
    //�Z�b�g�����͂��̃g���[�X�J���[//Takeuchi
    EV3_LOG("Set Trace Color black = %f, Set Trace Color white = %f\n", traceColor.black, traceColor.white);//Takeuchi
    //���ۂɃZ�b�g����Ă���Z�b�g�J�A���[//Takeuchi
    traceColor = Drive::LineTrace::GetTraceColor();//Takeuchi(���݃Z�b�g����Ă���g���[�X�J���[���擾)//Takeuchi
    EV3_LOG("Now Trace Color black = %f, Now Trace Color white = %f\n", traceColor.black, traceColor.white);//Takeuchi

    if(!Drive::Drive(pwm)){
        EV3_LOG("ERROR_LINETRACER_DRIVE\n");
        return false;
    }
    
  // straightRunner i_straightRunner;
  // if(!i_straightRunner.run(pwm)){return false;}
    
    return true;
}