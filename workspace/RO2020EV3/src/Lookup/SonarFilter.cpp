#include "SonarFilter.h"

/// Public
SonarFilter* SonarFilter::instance = nullptr;

int16 SonarFilter::GetAvg()
{
    int16 avg_val = 0;

    for(auto i=0;i<3;i++){
       if(this->GetInstance()->avg_datas[i] == 0){
          return 99;
       }
    }

    // 平均値を返す
    for(auto i=0;i < 3;i++){
      avg_val += this->GetInstance()->avg_datas[i];
    }

    return avg_val;
}

bool SonarFilter::FilterInput()
{
    int16 tavg = 0;
    #ifdef __LOOKUP_DEBUG__
    tavg = distance;
    #else
    tavg = RyujiEv3Engine::GetSonarSensor()->getDistance();
    #endif

    if( tavg > MAX_SONER || tavg < MIN_SONER)
    {
        return false;
    }
        this->GetInstance()->avg_datas[this->GetInstance()->data_pointer] = tavg;
        this->GetInstance()->data_pointer++;

    if( this->GetInstance()->data_pointer >= 3){
        this->GetInstance()->data_pointer = 0;
    }

    return true;
}

void SonarFilter::RestartData()
{
    avg_datas = {0,0,0};
}

#ifdef __LOOKUP_DEBUG__
void SonarFilter::SetAvg(int16 test_val1,int16 test_val2,int16 test_val3)
{
    avg_datas = {test_val1,test_val2,test_val3};
}

void SonarFilter::StbGetDistance(int distance)
{
    this->GetInstance()->distance = distance;
    return;
}
#endif

SonarFilter* SonarFilter::GetInstance()
{

    if(!instance){
        instance = new SonarFilter;
    }

   return instance;

}

SonarFilter::SonarFilter(){

}

SonarFilter::~SonarFilter(){
    
}
