#include "tailPositionerTest.h"

bool tailPositionerTest::test() {
  // angle:Šp“x:-10~200
  // speed:‘¬“x:0~100
  // blocking:bool
  tailPositioner i_tailPositioner;
  InfoTail infoTails[12] = {
      {-11, 0, false},   {-10, 0, false},   {105, 0, false}, {200, 0, false},
      {201, 0, false},   {105, -1, false},  {105, 0, false}, {105, 50, false},
      {105, 100, false}, {105, 101, false}, {105, 50, true}, {-10, 100, true}};

  CaseTailPositioner caseTailPositioner[13] = {
      {&infoTails[0], false}, {&infoTails[1], true},  {&infoTails[2], true},
      {&infoTails[3], true},  {&infoTails[4], false}, {&infoTails[5], false},
      {&infoTails[6], true},  {&infoTails[7], true},  {&infoTails[8], true},
      {&infoTails[9], false}, {&infoTails[10], true}, {&infoTails[11], true},
      {NULL, false}};

  for (int i = 0; i < 13; i++) {
    if (caseTailPositioner[i].retValue !=
        i_tailPositioner.run(caseTailPositioner[i].info)) {
      // log
      EV3_LOG(
          "TEST_ERR:tailPositioner.run(info)...i=%d, infoTails.angle=%d, "
          "infoTails.speed=%d, infoTails.blocking=%d",
          i, infoTails[i].angle, infoTails[i].speed, infoTails[i].blocking);
      return false;
    }
  }
  return true;
}