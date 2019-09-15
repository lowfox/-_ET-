#include "seesawRunnerTest.h"

bool seesawRunnerTest::test() {
  seesawRunner i_seesawRunner;
  if (true != i_seesawRunner.run(direction::back)) {
    EV3_LOG("TEST_ERR:seesawRunner.run() ... direction::back, ret=true\n");
    return false;
  }
  if (true != i_seesawRunner.run(direction::forward)) {
    EV3_LOG("TEST_ERR:seesawRunner.run() ... direction::forward, ret=true\n");
    return false;
  }

  return true;
}