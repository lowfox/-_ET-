#pragma once
#include <RyujiEv3.h>
#include <array>
#include "IDrive.h"
#include "LineTraceDrive.h"

class DriveManager {
 private:
  std::array<IDrive*, 2> m_drive;

  DriveMode m_mode;

  IDrive* pDrive = nullptr;

  int32 m_speed = 0;

  int32 m_turn = 0;

 public:
  DriveManager();

  ~DriveManager();

  bool drive(int32 speed, int32 turn);

  bool stop();

  bool rotate();

  void update();

  bool setDriveMode(DriveMode mode);

  DriveMode getDriveMode();

  LineTraceDrive* getLineTraceDrive();
};