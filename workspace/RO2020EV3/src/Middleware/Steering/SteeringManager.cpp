#include "SteeringManager.h"
#include "BalanceSteering.h"
#include "NomalSteering.h"

SteeringManager::SteeringManager() : m_mode(SteeringMode::Nomal) {
  m_sterring[static_cast<int32>(SteeringMode::Balance)] = new BalanceSterring;
  m_sterring[static_cast<int32>(SteeringMode::Nomal)]   = new NomalSterring;

  pSterring = m_sterring[static_cast<int32>(SteeringMode::Nomal)];
}

SteeringManager::~SteeringManager() {
  RyujiEv3Engine::GetLeftMotor()->stop(true);
  RyujiEv3Engine::GetRightMotor()->stop(true);

  for (auto& itr : m_sterring) {
    delete itr;
  }
}

bool SteeringManager::setMode(SteeringMode mode) {
  if (m_mode == mode) {
    return false;
  }

  m_mode = mode;

  pSterring = m_sterring[static_cast<int32>(mode)];

  if (m_mode == SteeringMode::Balance) {
    m_leftCountOffset += RyujiEv3Engine::GetLeftMotor()->getCounts();
    m_rightCountOffset += RyujiEv3Engine::GetRightMotor()->getCounts();
  }

  return pSterring->init();
}

SteeringMode SteeringManager::getMode() { return m_mode; }

bool SteeringManager::drive(int32 speed, int32 turn) {
  return pSterring->drive(speed, turn);
}

bool SteeringManager::stop() { return pSterring->stop(); }

float SteeringManager::driveDistance() { return m_driveDistance; }

void SteeringManager::resetDriveDistance() { m_driveDistance = 0.0f; }


bool SteeringManager::update() {
  driveDistanceUpdate();
  return pSterring->update();
}

void SteeringManager::driveDistanceUpdate() {
  constexpr float TIRE_DIAMETER = 100.5f;
  constexpr float PI            = 3.1415926535f;

  const float angleLeft =
      RyujiEv3Engine::GetLeftMotor()->getCounts() + m_leftCountOffset;
  const float angleRight =
      RyujiEv3Engine::GetRightMotor()->getCounts() + m_rightCountOffset;
  static float prevAngleLeft  = 0.0f;
  static float prevAngleRight = 0.0f;

  const float distance4msLeft =
      ((PI * TIRE_DIAMETER) / 360.0f) * (angleLeft - prevAngleLeft);
  const float distance4msRight =
      ((PI * TIRE_DIAMETER) / 360.0f) * (angleRight - prevAngleRight);
  const float distance4ms = (distance4msLeft + distance4msRight) / 2.0f;

  m_driveDistance += distance4ms;

  prevAngleLeft  = angleLeft;
  prevAngleRight = angleRight;
}
