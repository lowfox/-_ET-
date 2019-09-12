#pragma once
#include <RyujiEv3.h>
#include <array>
#include "ISteering.h"
#include <Steering.h>

class SteeringManager {
 private:
  std::array<ISteering*, 2> m_sterring;

  SteeringMode m_mode;

  ISteering* pSterring;

  int32 m_leftCountOffset = 0;

  int32 m_rightCountOffset = 0;

  float m_driveDistance = 0.0f;

 public:
  SteeringManager();

  ~SteeringManager();

  bool setMode(SteeringMode mode);

  SteeringMode getMode();

  bool drive(int32 speed, int32 turn);

  bool stop();

  float driveDistance();

  void resetDriveDistance();

  bool update();

 private:
  void driveDistanceUpdate();
};