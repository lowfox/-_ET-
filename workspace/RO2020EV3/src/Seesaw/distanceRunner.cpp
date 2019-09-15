#include "distanceRunner.h"

bool distanceRunner::run(infoDistanceRun* info) {
  // info
  // pwm:-100~100 int32
  // distance:0.5~790.0 flaot
  RyujiEv3Engine::GetLED()->setColor(LED_Color::ORANGE);
  EV3_LOG("distanceRunner__start\n");
  if (info == NULL) {
    EV3_LOG_ERROR("distanceRunner__info==NULL\n");
    return false;
  }
  if (info->pwm > 100 || info->pwm < -100) {
    return false;
  }
  if (info->distance > 790.0f || info->distance < -790.0f ||
      info->distance == 0.0f) {
    return false;
  }

  straightRunner i_straightRunner;

  m_startDistance = Steering::GetDistance();

  if (!i_straightRunner.run(info->pwm)) {
    return false;
  }

  if (info->distance > 0) {
    while ((Steering::GetDistance() - m_startDistance) <= info->distance) {
      // EV3_LOG("distance=%f,
      // nowDistance=%f\n",info->distance,Steering::GetDistance());
    }
  } else {
    while ((Steering::GetDistance() - m_startDistance) >= info->distance) {
      // EV3_LOG("distance=%f,
      // nowDistance=%f\n",info->distance,Steering::GetDistance());
    }
  }
  if (!Drive::Stop()) {
    return false;
  }
  EV3_LOG("distanceRunner__finish\n");
  RyujiEv3Engine::GetLED()->setColor(LED_Color::OFF);
  return true;
}