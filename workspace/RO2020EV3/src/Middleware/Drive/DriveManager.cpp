#include "DriveManager.h"
#include "NomalDrive.h"
#include "../Steering/SteeringManager.h"
#include "../DriveEngine/DriveEngine.h"

DriveManager::DriveManager() : m_mode(DriveMode::Nomal) {
  m_drive[static_cast<int32>(DriveMode::Nomal)]     = new NomalDrive;
  m_drive[static_cast<int32>(DriveMode::LineTrace)] = new LineTraceDrive;

  pDrive = m_drive[static_cast<int32>(DriveMode::Nomal)];
  pDrive->init();
}

DriveManager::~DriveManager() {
  for (auto& itr : m_drive) {
    delete itr;
  }
}

bool DriveManager::drive(int32 speed, int32 turn) {
  return pDrive->drive(speed, turn);
}

bool DriveManager::stop() { return pDrive->stop(); }

bool DriveManager::rotate() {
  if (DriveEngine::GetSteering()->getMode() == SteeringMode::Balance) {
    return false;
  }

  if (!pDrive->rotate()) {
    return false;
  }

  return true;
}

void DriveManager::update() { pDrive->update(); }

bool DriveManager::setDriveMode(DriveMode mode) {
  if (m_mode == mode) {
    return false;
  }

  if (!m_drive[static_cast<int32>(mode)]->init()) {
    return false;
  }

  pDrive = m_drive[static_cast<int32>(mode)];

  m_mode = mode;

  return true;
}

DriveMode DriveManager::getDriveMode() { return m_mode; }

LineTraceDrive* DriveManager::getLineTraceDrive() {
  return dynamic_cast<LineTraceDrive*>(
      m_drive[static_cast<int32>(DriveMode::LineTrace)]);
}
