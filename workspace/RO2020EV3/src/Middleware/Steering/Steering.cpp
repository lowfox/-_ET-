#include <Steering.h>
#include "../DriveEngine/DriveEngine.h"
#include "SteeringManager.h"
#include "..//Drive/DriveManager.h"
#include "../app.h"

namespace Steering {
bool SetMode(SteeringMode mode) {
  return DriveEngine::GetSteering()->setMode(mode);
}

float GetDistance() { return DriveEngine::GetSteering()->driveDistance(); }
void ResetDistance() { DriveEngine::GetSteering()->resetDriveDistance(); }
}  // namespace Steering

// ステアリング周期ハンドラ
void drive_cyc(intptr_t unused) {
  DriveEngine::GetDrive()->update();
  DriveEngine::GetSteering()->update();
}
