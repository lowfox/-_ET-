#pragma once
#include "IDrive.h"

class NomalDrive : public IDrive {
 public:
  bool init() override;

  bool drive(int32 speed, int32 turn) override;

  bool stop() override;

  bool rotate() override;

  void update() override;
};