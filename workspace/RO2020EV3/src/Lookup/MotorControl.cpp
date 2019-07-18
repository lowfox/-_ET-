#include "MotorControl.h"
#include "../Logger/CLogger.h"

bool MotorControl::CompareVal()
{
    auto tracecolor=Drive::ColorCalibrate::GetTraceColor(53);
    Drive::LineTrace::SetTraceColor(tracecolor);
    Drive::SetDriveMode(DriveMode::LineTrace);
    //Drive::SetDriveMode(DriveMode::Nomal); //テスト用(後でLineTraceに変更)
    if(!Drive::Drive(5,0))
    {
        return false;
    }
    while(Steering::GetDistance() <= (this->start_val + this->offset_val)){}

    if(!Drive::Stop())
    {
        return false;
    }
    
    return true;
}


void MotorControl::SetStartDistance()
{
    #ifdef __LOOKUP_DEBUG__
    EV3_LOG_DEBUG("StartDistance %d[mm]",start_val);
    #else
    this->start_val=Steering::GetDistance();
    #endif
}

#ifdef __LOOKUP_DEBUG__
void MotorControl::StbSetStartDistance(float distance)
{
    this->start_val = distance;
}
#endif

void MotorControl::SetOffset()
{

    if(SonarControl::GetInstance()->GetAvg() != 99){
        offset_val = SonarControl::GetInstance()->GetAvg();
        this->offset_val += 150;   // this->offset_val = 150;
        #ifdef __LOOKUP_DEBUG__
        EV3_LOG_DEBUG("SetOffset %d[mm]",offset_val);
        #endif
    }
        #ifdef __LOOKUP_DEBUG__
        EV3_LOG_DEBUG("SonarControl::GetInstance()->GetAvg() == 99");
        #endif
    return ;
}

void MotorControl::UpPassCnt()
{
    this->pass_count +=1;
    #ifdef __LOOKUP_DEBUG__
    EV3_LOG_DEBUG("StartDistance %d[mm]",pass_count);
    #endif
}

int8_t MotorControl::GetPassCount()
{
    return this->pass_count;
}