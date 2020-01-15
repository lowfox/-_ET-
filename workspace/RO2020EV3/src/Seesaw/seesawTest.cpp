#include "seesawTest.h"

bool seesawTest::run() {
  tailPositionerTest i_tailPositionerTest;
  angleDetectorTest i_angleDetectorTest;
  angularVelocityDetectorTest i_angularVelocityDetectorTest;
  straightRunnerTest i_straghtRunnerTest;
  lineTracerTest i_lineTracerTest;
  distanceRunnerTest i_distanceRunnerTest;

  if (!i_tailPositionerTest.test()) {
    return false;
  }
  if (!i_angleDetectorTest.setTargetValueTest()) {
    return false;
  }
  if (!i_angleDetectorTest.detectTest()) {
    return false;
  }
  if (!i_angularVelocityDetectorTest.setOffsetTest()) {
    return false;
  }
  if (!i_angularVelocityDetectorTest.detectTest()) {
    return false;
  }
  if (!i_lineTracerTest.test()) {
    return false;
  }
  if (!i_straghtRunnerTest.test()) {
    return false;
  }
  if (!i_distanceRunnerTest.test()) {
    return false;
  }

  return true;
}