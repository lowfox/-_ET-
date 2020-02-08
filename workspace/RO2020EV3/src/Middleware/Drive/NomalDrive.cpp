#include "NomalDrive.h"
#include "../DriveEngine/DriveEngine.h"
#include "../Steering/SteeringManager.h"
#include "DriveManager.h"

bool NomalDrive::init() { return true; }

bool NomalDrive::drive(int32 speed, int32 turn) {
  return DriveEngine::GetSteering()->drive(speed, turn);
}

bool NomalDrive::stop() { return DriveEngine::GetSteering()->stop(); }

bool NomalDrive::rotate() {
  if (!DriveEngine::GetSteering()->drive(0, -10)) {
    return false;
  }

  TraceColor traceColor =
      DriveEngine::GetDrive()->getLineTraceDrive()->getTraceColor();

  tslp_tsk(1000);

  while (true) {
    const RGB rgb          = RyujiEv3Engine::GetColorSensor()->getRGB();
    const float rgbAverage = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);

    if (rgbAverage < static_cast<float>(traceColor.black * 1.5f)) {
      break;
    }
  }

  return DriveEngine::GetDrive()->stop();
}

void NomalDrive::update() {}
