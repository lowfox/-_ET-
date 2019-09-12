#include"straightRunner.h"

bool straightRunner::run(int32 pwm){
   Drive::SetDriveMode(DriveMode::Nomal);
   if(pwm>100 || pwm<-100){return false;}
   if(!Drive::Drive(pwm,0)){
      return false;
   }
  return true;
}