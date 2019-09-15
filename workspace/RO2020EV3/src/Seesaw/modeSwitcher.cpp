#include "modeSwitcher.h"

bool modeSwitcher::run(void) {
  EV3_LOG("modeSwitcher__start\n");
  tailPositioner i_tailPositioner;
  braker i_braker;
  /*
      EV3_LOG("Asobi nakusi tyuu ...\n");
      if(!Steering::SetMode(SteeringMode::Balance)){
          EV3_LOG_ERROR("Steering::setmode()\n");
          //return false;
      }
      dly_tsk(2000);
    */
  RyujiEv3Engine::GetTailMotor()->resetCounts();

  /*
      EV3_LOG("hosei mae kakudo =
     %d",RyujiEv3Engine::GetTailMotor()->getCounts());
      if(!i_tailPositioner.run(&m_initTail)){
          return false;}
      dly_tsk(2000);
      if(!i_tailPositioner.run(&m_asobiNoTail)){return false;}
      EV3_LOG("hosei nasi go kakudo =
     %d",RyujiEv3Engine::GetTailMotor()->getCounts()); EV3_LOG("delay...15sec");
      dly_tsk(15000);
  */
  //�V�т̕␳�v���O�����B
  if (!i_tailPositioner.run(&m_asobiHoseiTail)) {
    return false;
  }
  dly_tsk(1000);
  if (!RyujiEv3Engine::GetTailMotor()->stop(false)) {
    EV3_LOG("stopERROR!");
    return false;
  }
  if (!RyujiEv3Engine::GetTailMotor()->resetCounts()) {
    EV3_LOG("resetCountsERROR");
    return false;
  }

  if (!i_tailPositioner.run(&m_initTail)) {
    return false;
  }
  dly_tsk(1000);

  /*
      if(!i_tailPositioner.run(&m_asobiNoTail)){return false;}
      EV3_LOG("hosei go kakudo =
     %d",RyujiEv3Engine::GetTailMotor()->getCounts()); while(1){}
  */
  if (!Steering::SetMode(SteeringMode::Nomal)) {
    EV3_LOG_ERROR("Steering::setmode()\n");
    // return false;
  }

  float oneDistance = Steering::GetDistance();
  if (!Drive::Drive(3)) {
    return false;
  }
  while ((Steering::GetDistance() - oneDistance) < 40.0f) {
  }
  // Drive::Stop(false);
  // if(!i_distanceRunner.run(&m_modeSwitchRun1)){return false;}
  // if(!i_distanceRunner.run(&m_modeSwitchRun2)){return false;}
  if (!RyujiEv3Engine::GetLeftMotor()->stop(false)) {
    return false;
  }
  if (!RyujiEv3Engine::GetRightMotor()->stop(false)) {
    return false;
  }

  dly_tsk(1000);

  if (!RyujiEv3Engine::GetGyroSensor()->reset()) {
    EV3_LOG("GYRO_RESET_FALSE\n");
  }

  EV3_LOG("modeSwitcher__finish\n");
  return true;
}