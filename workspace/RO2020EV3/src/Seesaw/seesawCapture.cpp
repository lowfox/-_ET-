
#include "seesawCapture.h"

bool seesawCapture::run(void) {
  EV3_LOG("seeawCapture__start\n");

  gotoSeesaw i_gotoSeesaw;
  seesawClimber i_seeswClimber;
  seesawDouble i_seesawDouble;
  seesawDesc i_seesawDesc;
  garageInit i_garageInit;

  RyujiEv3Engine::GetSpeaker()->setVolume(1);
  if (!i_gotoSeesaw.run()) {
    EV3_LOG_ERROR("gotoSeesaw__false\n");
    return false;
  }
  if (!i_seeswClimber.run()) {
    return false;
  }
  if (!i_seesawDouble.run()) {
    return false;
  }

  if (!i_seesawDesc.run()) {
    return false;
  }

  if (!i_garageInit.run()) {
    return false;
  }

  return true;
}