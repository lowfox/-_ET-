#pragma once
#include <RyujiEv3.h>

class ISteering {
 public:
  virtual ~ISteering(){};

  virtual bool init() { return false; };

  virtual bool drive(int32 speed, int32 turn) = 0;

  virtual bool stop() = 0;

  virtual bool update() { return true; };
};