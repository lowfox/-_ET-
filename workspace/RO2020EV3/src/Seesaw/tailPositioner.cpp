#include "tailPositioner.h"

bool tailPositioner::run(InfoTail* info) {
  EV3_LOG("tailPositioner__start\n");
  // angle:Šp“x:-10~200
  // speed:‘¬“x:0~100
  // blocking:bool
  if (info->angle > 200 || info->angle < -30) {
    return false;
  }
  if (info->speed > 100 || info->speed < 0) {
    return false;
  }
  if (info->blocking != true && info->blocking != false) {
    return false;
  }
  int32 nowAngle   = (RyujiEv3Engine::GetTailMotor()->getCounts());
  int32 inputAngle = (info->angle) - nowAngle;
  EV3_LOG("tailPositioner__inputAngle=%d, info->Angle=%d, nowAngle=%d\n",
          inputAngle, info->angle, nowAngle);
  if (!RyujiEv3Engine::GetTailMotor()->setCounts(inputAngle, info->speed,
                                                 info->blocking)) {
    return false;
  }
  if (info->blocking == false) {
    return true;
  }

  if (!RyujiEv3Engine::GetTailMotor()->stop(true)) {
    return false;
  }
  EV3_LOG("tailPositioner__finish\n");
  return true;
}
