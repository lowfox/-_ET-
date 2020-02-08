#include "LookUpTest.h"
#include "Debug.h"

#ifdef __LOOKUP_DEBUG__

LookUpTest::LookUpTest() {
  // sensor値
  sd_test[0].distance        = {-1, 0, 1};
  sd_test[0].distance_retval = false;
  sd_test[1].distance        = {4, 5, 6};
  sd_test[1].distance_retval = false;
  sd_test[2].distance        = {5, 6, 7};
  sd_test[2].distance_retval = true;
  sd_test[3].distance        = {20, 21, 22};
  sd_test[3].distance_retval = true;
  sd_test[4].distance        = {29, 30, 31};
  sd_test[4].distance_retval = false;
  sd_test[5].distance        = {30, 31, 32};
  sd_test[5].distance_retval = false;

  // sonar比較
  sc_test[0].stop_distance = {STOP_DISTANCE, STOP_DISTANCE, STOP_DISTANCE};
  sc_test[0].stop_distance_retval = true;
  sc_test[1].stop_distance        = {STOP_DISTANCE - 1, STOP_DISTANCE - 1,
                              STOP_DISTANCE - 1};
  sc_test[1].stop_distance_retval = true;
  sc_test[2].stop_distance        = {STOP_DISTANCE + 1, STOP_DISTANCE + 1,
                              STOP_DISTANCE + 1};
  sc_test[2].stop_distance_retval = false;
  sc_test[3].stop_distance        = {MIN_SONER, MIN_SONER, MIN_SONER};
  sc_test[3].stop_distance_retval = true;
  sc_test[4].stop_distance = {MIN_SONER - 1, MIN_SONER - 1, MIN_SONER - 1};
  sc_test[4].stop_distance_retval = true;
  sc_test[5].stop_distance = {MIN_SONER + 1, MIN_SONER + 1, MIN_SONER + 1};
  sc_test[5].stop_distance_retval = true;

  // sonarinput
  si_test[0].input_data        = STOP_DISTANCE;
  si_test[0].input_data_retval = true;
  si_test[1].input_data        = MAX_SONER - 1;
  si_test[1].input_data_retval = true;
  si_test[2].input_data        = MAX_SONER;
  si_test[2].input_data_retval = true;
  si_test[3].input_data        = MAX_SONER + 1;
  si_test[3].input_data_retval = false;
  si_test[4].input_data        = MIN_SONER - 1;
  si_test[4].input_data_retval = false;
  si_test[5].input_data        = MAX_SONER;
  si_test[5].input_data_retval = true;
  si_test[6].input_data        = MAX_SONER + 1;
  si_test[6].input_data_retval = true;

  // tail
  t_test[0].counts         = {MIN_TARGET - 1, 1};
  t_test[0].counts_retval  = false;
  t_test[1].counts         = {MIN_TARGET - 1, -1};
  t_test[1].counts_retval  = false;
  t_test[2].counts         = {MIN_TARGET, 1};
  t_test[2].counts_retval  = true;
  t_test[3].counts         = {MIN_TARGET, -1};
  t_test[3].counts_retval  = false;
  t_test[4].counts         = {MIN_TARGET + 1, 1};
  t_test[4].counts_retval  = false;
  t_test[5].counts         = {MIN_TARGET + 1, -1};
  t_test[5].counts_retval  = false;
  t_test[6].counts         = {MAX_TARGET - 1, 1};
  t_test[6].counts_retval  = false;
  t_test[7].counts         = {MAX_TARGET - 1, -1};
  t_test[7].counts_retval  = false;
  t_test[8].counts         = {MAX_TARGET, 1};
  t_test[8].counts_retval  = true;
  t_test[9].counts         = {MAX_TARGET, -1};
  t_test[9].counts_retval  = false;
  t_test[10].counts        = {MAX_TARGET + 1, 1};
  t_test[10].counts_retval = false;
  t_test[11].counts        = {MAX_TARGET + 1, -1};
  t_test[11].counts_retval = false;

  // Motordistance
  mt_test[0] = 98;
  mt_test[1] = 99;
  mt_test[2] = 100;
  mt_test[3] = -1;
  mt_test[4] = 0;
  mt_test[5] = 1;

  // Motorcount
  mc_test[0] = -1;
  mc_test[1] = 0;
  mc_test[2] = 1;
  mc_test[3] = 5;
  mc_test[4] = 10;
  mc_test[5] = 15;

  // MotorCompareVal
  mcv_test[0].offset         = 10;
  mcv_test[0].start          = 9.9;
  mcv_test[0].compare_retval = true;
  mcv_test[1].offset         = 10;
  mcv_test[1].start          = 10.0;
  mcv_test[1].compare_retval = false;
  mcv_test[2].offset         = 10;
  mcv_test[2].start          = 9.8;
  mcv_test[2].compare_retval = false;
  mcv_test[3].offset         = 9;
  mcv_test[3].start          = 10.0;
  mcv_test[3].compare_retval = true;
  mcv_test[4].offset         = 10;
  mcv_test[4].start          = 10.0;
  mcv_test[4].compare_retval = false;
  mcv_test[5].offset         = 11;
  mcv_test[5].start          = 10.0;
  mcv_test[5].compare_retval = false;

  // emergencyreflects
  el_test[0].reflects        = MIN_REFLRCT - 1;
  el_test[0].reflects_retval = false;
  el_test[1].reflects        = MIN_REFLRCT;
  el_test[1].reflects_retval = false;
  el_test[2].reflects        = MIN_REFLRCT + 1;
  el_test[2].reflects_retval = true;
  el_test[3].reflects        = MAX_REFLRCT - 1;
  el_test[3].reflects_retval = true;
  el_test[4].reflects        = MAX_REFLRCT;
  el_test[4].reflects_retval = false;
  el_test[5].reflects        = MAX_REFLRCT + 1;
  el_test[5].reflects_retval = false;

  // emergency left
  elf_test[0].left_turn_deg        = {109, -107};
  elf_test[0].left_turn_deg_retval = false;
  elf_test[1].left_turn_deg        = {109, -108};
  elf_test[1].left_turn_deg_retval = true;
  elf_test[2].left_turn_deg        = {108, -107};
  elf_test[2].left_turn_deg_retval = false;
  elf_test[3].left_turn_deg        = {108, -108};
  elf_test[3].left_turn_deg_retval = false;

  // emergency right
  er_test[0].right_turn_deg        = {-107, 107};
  er_test[0].right_turn_deg_retval = false;
  er_test[1].right_turn_deg        = {-107, 109};
  er_test[1].right_turn_deg_retval = false;
  er_test[2].right_turn_deg        = {-109, 107};
  er_test[2].right_turn_deg_retval = false;
  er_test[3].right_turn_deg        = {-108, 108};
  er_test[3].right_turn_deg_retval = false;
}

void LookUpTest::TestSonarFilterGetAvg() {
  for (auto i = 0; i < SONAR_DISTANCE; i++) {
    SonarFilter::GetInstance()->SetAvg(
        sd_test[i].distance[0], sd_test[i].distance[1], sd_test[i].distance[2]);
    EV3_LOG_DEBUG("SonarDistance %d[cm]", SonarFilter::GetInstance()->GetAvg());
  }

  EV3_LOG_DEBUG("test1END");
  return;
}

void LookUpTest::TestSonarFilterFilterInput() {
  for (auto i = 0; i < SONAR_DISTANCE; i++) {
    SonarFilter::GetInstance()->StbGetDistance(si_test[i].input_data);
    assertEquals(SonarFilter::GetInstance()->FilterInput(),
                 si_test[i].input_data_retval);
  }
  EV3_LOG_DEBUG("test2END");
  return;
}

void LookUpTest::TestSonarControlCheckAvg() {
  for (auto i = 0; i < SONAR_CHECK; i++) {
    SonarFilter::GetInstance()->SetAvg(sc_test[i].stop_distance[0],
                                       sc_test[i].stop_distance[1],
                                       sc_test[i].stop_distance[2]);
    assertEquals(SonarControl::GetInstance()->CheckAvg(),
                 sc_test[i].stop_distance_retval);
  }
  EV3_LOG_DEBUG("test3END");
}

void LookUpTest::TestSonarControlGetAvg() {
  for (auto i = 0; i < SONAR_GETAVG; i++) {
    SonarControl::GetInstance()->SetAvg(i);
    EV3_LOG_DEBUG("SonarDistance %d[cm]",
                  SonarControl::GetInstance()->GetAvg());
  }
  EV3_LOG_DEBUG("test4(SonarEND)END");
}

void LookUpTest::TestTailAngle() {
  for (auto i = 0; i < TAIL; i++) {
    assertEquals(tctrl.Angle(t_test[i].counts[0], t_test[i].counts[1]),
                 t_test[i].counts_retval);
  }
  EV3_LOG_DEBUG("test5END");
}

void LookUpTest::TestTailStageAngle() {
  for (auto i = 0; i < TAIL; i++) {
    assertEquals(tctrl.StageAngle(MIN_TARGET - 1), false);
    assertEquals(tctrl.StageAngle(MIN_TARGET), true);
    assertEquals(tctrl.StageAngle(MIN_TARGET + 1), false);

    assertEquals(tctrl.StageAngle(MAX_TARGET - 1), false);
    assertEquals(tctrl.StageAngle(MAX_TARGET), true);
    assertEquals(tctrl.StageAngle(MAX_TARGET + 1), false);
  }
  EV3_LOG_DEBUG("test6(TailEND)END");
}

void LookUpTest::TestMotorSetStartDistance() {
  mctrl.StbSetStartDistance(10.0);
  mctrl.SetStartDistance();
  mctrl.StbSetStartDistance(12.0);
  mctrl.SetStartDistance();
  EV3_LOG_DEBUG("test7END");
}

void LookUpTest::TestMotorSetOffset() {
  for (auto i = 0; i < MOTOR; i++) {
    SonarControl::GetInstance()->SetAvg(mt_test[i]);
    mctrl.SetOffset();
  }
  EV3_LOG_DEBUG("test8END");
}

void LookUpTest::TestMotorCompareVal() {
  mctrl.StbCompareVal(mcv_test[0].start, mcv_test[0].offset);
  assertEquals(mctrl.CompareVal(), mcv_test[0].compare_retval);

  EV3_LOG_DEBUG("test9END");
}

void LookUpTest::TestMotorUpPassCount() {
  mctrl.StbSetUpPassCnt(0);
  for (auto i = 0; i < MOTOR; i++) {
    mctrl.UpPassCnt();
  }
  EV3_LOG_DEBUG("test10END");
}

void LookUpTest::TestMotorGetPassCount() {
  for (auto i = 0; i < MOTOR; i++) {
    mctrl.StbSetUpPassCnt(mc_test[i]);
    mctrl.UpPassCnt();
  }
  EV3_LOG_DEBUG("test11(MotorEND)END");
}

void LookUpTest::TestEmergencyLeftTurn() {
  for (auto i = 0; i < LEFTDEG; i++) {
    ectrl.StbLeftTurnAngle(elf_test[i].left_turn_deg[0],
                           elf_test[i].left_turn_deg[1]);
    assertEquals(ectrl.LeftTurn(), elf_test[i].left_turn_deg_retval);
  }
  EV3_LOG_DEBUG("test12END");
}

void LookUpTest::TestEmergencyRightTurn() {
  for (auto i = 0; i < RIGHTDEG; i++) {
    ectrl.StbRightTurnAngle(er_test[i].right_turn_deg[0],
                            er_test[i].right_turn_deg[1]);
    assertEquals(ectrl.LeftTurn(), er_test[i].right_turn_deg_retval);
  }
  EV3_LOG_DEBUG("test13END");
}

void LookUpTest::TestEmergencyLineCheck() {
  for (auto i = 0; i < EMERGENCY; i++) {
    ectrl.StbGetColor(el_test[i].reflects);
    assertEquals(ectrl.LineCheck(), el_test[i].reflects_retval);
  }
  EV3_LOG_DEBUG("test14END");
}

void LookUpTest::assertEquals(bool result, bool retval) {
  if (result != retval) {
    EV3_LOG_DEBUG("ERROR");
  }
  return;
}
#endif