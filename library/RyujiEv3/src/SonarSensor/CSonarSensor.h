#pragma once
#include <Interface/ISonarSensor.h>
#include <RyujiEv3Port.h>

namespace RyujiEv3 {
class CSonarSensor : public ISonarSensor {
 private:
  SensorPort port;

 public:
  bool init(SensorPort port);

  int16 getDistance() override;
};
}  // namespace RyujiEv3