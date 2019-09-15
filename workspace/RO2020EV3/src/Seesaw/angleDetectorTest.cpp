#include "angleDetectorTest.h"

bool angleDetectorTest::setTargetValueTest() {
  CaseAngleDetector caseAngleTarget[7] = {
      {-181, false}, {-180, true}, {-1, true},  {0, true},
      {1, true},     {180, true},  {181, false}};

  angleDetector i_angleDetector;
  for (int i = 0; i < 7; i++) {
    // test of setTargetValue
    if (caseAngleTarget[i].retValue !=
        i_angleDetector.setTargetValue(caseAngleTarget[i].targetValue)) {
      // log
      EV3_LOG(
          "TEST_ERR:angleDetector.setTargetValue ...i=%d, targetValue=%d, "
          "retVal=%d\n",
          i, caseAngleTarget[i].targetValue, caseAngleTarget[i].retValue);
      return false;
    }
  }

  return true;
}

bool angleDetectorTest::detectTest() {
  // test of detect
  angleDetector i_angleDetector;

  int16 testTargetValue   = 40;
  int16 caseDetectValue[] = {37, 38, 40, 42, 43};
  bool retDetect[]        = {false, true, true, true, false};
  i_angleDetector.setTargetValue(testTargetValue);
  for (int i = 0; i < 5; i++) {
#ifdef TESTMODE
    i_angleDetector.setTestValue(caseDetectValue[i]);
#endif
    if (retDetect[i] != i_angleDetector.detect()) {
      EV3_LOG(
          "TEST_ERR:angleDetector.detect ...i=%d, targetValue=%d, "
          "caseDetectValue=%d, retVal=%d\n",
          i, testTargetValue, caseDetectValue[i], retDetect[i]);
      return false;
    }
  }

  return true;
}