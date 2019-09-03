#include "EmergencyControl.h"
#include "../../app.h"

bool EmergencyControl::LeftTurn()
{
#ifdef __LOOKUP_DEBUG__
//60度回転
if(right_deg < 108 &&left_deg > -108)
{
    return true;
}
#else

  auto left_deg = RyujiEv3Engine::GetLeftMotor()->getCounts();
  auto right_deg = RyujiEv3Engine::GetRightMotor()->getCounts(); 

  RyujiEv3Engine::GetRightMotor()->setCounts(108,1,false);
  RyujiEv3Engine::GetLeftMotor()->setCounts(-108,1,true);

  if((RyujiEv3Engine::GetRightMotor()->getCounts() - right_deg) < 108 &&
    (RyujiEv3Engine::GetLeftMotor()->getCounts() - left_deg) > -108)
  {
      ev3_stp_cyc(COLOR_CYC);
      return true;
  }
  #endif
    return false;

}

bool EmergencyControl::RightTurn()
{
  #ifdef __LOOKUP_DEBUG__
  //60度回転
  if(right_deg > -108 &&left_deg< 108)
    {
        return true;
    }
  #else
  auto left_deg = RyujiEv3Engine::GetLeftMotor()->getCounts();
  auto right_deg = RyujiEv3Engine::GetRightMotor()->getCounts(); 

  RyujiEv3Engine::GetRightMotor()->setCounts(-108,1,false);
  RyujiEv3Engine::GetLeftMotor()->setCounts(108,1,true);

    if((RyujiEv3Engine::GetRightMotor()->getCounts() - right_deg) > -108 &&
      (RyujiEv3Engine::GetLeftMotor()->getCounts() - left_deg) < 108)
    {
        ev3_stp_cyc(COLOR_CYC);
        return true;
    }

    ev3_stp_cyc(COLOR_CYC);
    #endif
  return false;
}


bool EmergencyControl::LineCheck()
{
  #ifdef __LOOKUP_DEBUG__
  if(reflect > MIN_REFLRCT && reflect < MAX_REFLRCT)
  {
    return true;
  }
  #else
  if(RyujiEv3Engine::GetColorSensor()->getReflect() > MIN_REFLRCT && 
     RyujiEv3Engine::GetColorSensor()->getReflect() < MAX_REFLRCT)
  {
    return true;
  }
  #endif
  return false;
}


  #ifdef __LOOKUP_DEBUG__
  void EmergencyControl::StbGetColor(uint8 ireflect)
  {
    this->reflect = ireflect;
    
    return;
  }

  void EmergencyControl::StbLeftTurnAngle(int32 left,int32 right)
  {
      this->left_deg  = left;
      this->right_deg = right;
  }

  void EmergencyControl::StbRightTurnAngle(int32 left,int32 right)
  {
      this->left_deg  = left;
      this->right_deg = right;
  }

  #endif

void EmergencyControl::StartColor()
{
    ev3_sta_cyc(COLOR_CYC);
}

void color_cyc(intptr_t exinf)
{
    if(RyujiEv3Engine::GetColorSensor()->getReflect() > 10 && 
       RyujiEv3Engine::GetColorSensor()->getReflect() < 40)
    {
        Drive::Stop();
        tslp_tsk(350);
        ev3_stp_cyc(COLOR_CYC);
    }
}