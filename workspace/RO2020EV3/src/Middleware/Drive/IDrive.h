#pragma once
#include <RyujiEv3.h>

class IDrive {
 public:
  virtual ~IDrive() {}

  virtual bool init() = 0;

  virtual bool drive(int32 speed, int32 turn) = 0;

  virtual bool stop() = 0;

  virtual bool rotate() = 0;

  virtual void update() = 0;
};