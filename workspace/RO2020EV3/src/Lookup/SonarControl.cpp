#include "SonarControl.h"
#include "../../app.h"

SonarControl* SonarControl::instance = nullptr;

SonarControl* SonarControl::GetInstance()
{
   if(!instance)
   {
       instance = new SonarControl;
   }
   return instance;
}

void SonarControl::SonarRun()
{
    ev3_sta_cyc(SONAR_CYC);
}


int16 SonarControl::GetAvg(){
    return this->GetInstance()->avg_data;
}

#ifdef __LOOKUP_DEBUG__
void SonarControl::SetAvg(int16 avg)
{
    this->GetInstance()->avg_data = avg;
    return;
}
#endif

bool SonarControl::CheckAvg()
{
    // 5以下追加
    if( SonarFilter::GetInstance()->GetAvg() <= STOP_DISTANCE )
    {    
        ev3_stp_cyc(SONAR_CYC);
        avg_data=SonarFilter::GetInstance()->GetAvg();
        return true;
    }
    return false;
}

SonarControl::SonarControl(){

}

SonarControl::~SonarControl(){
    
}

void sonar_cyc(intptr_t exinf)
{  
    SonarFilter::GetInstance()->FilterInput();
}