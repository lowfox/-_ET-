#pragma once
#include "Debug.h"

#ifdef __LOOKUP_DEBUG__
#include"TailControl.h"
#include "MotorControl.h"
#include "SonarControl.h"
#include "SonarFilter.h"
#include "EmergencyControl.h"
#include "../Logger/CLogger.h"
#include "TestData.h"

#define SONAR_DISTANCE 6
#define SONAR_GETAVG   6
#define SONAR_CHECK    6
#define SONAR_INPUT    6
#define TAIL          12
#define MOTOR          6
#define EMERGENCY      6
#define LEFTDEG        4
#define RIGHTDEG       4

class LookUpTest
{

private:

       TailControl           tctrl;

       MotorControl          mctrl;

       EmergencyControl      ectrl;

       SonarDistanceTest     sd_test[SONAR_DISTANCE];

       SonarCompareTest      sc_test[SONAR_CHECK];

       SonarInputTest        si_test[SONAR_INPUT];

       TailTest              t_test[TAIL];

       EmergencyLineTest     el_test[EMERGENCY];

       EmergencyLeftTurnTest elf_test[LEFTDEG];

       EmergencyRightTurnTest er_test[RIGHTDEG];

       MotorCompareTest       mcv_test[MOTOR];

       std::array<int16, SONAR_CHECK> SonarCheckData;
       
       int16                  mt_test[MOTOR];

       int8                   mc_test[MOTOR];

public:
  
       LookUpTest();

       void TestSonarFilterFilterInput();
       void TestSonarFilterGetAvg();

       void TestTailAngle();
       void TestTailStageAngle();

       void TestSonarControlCheckAvg();
       void TestSonarControlGetAvg();
       
       void TestMotorSetStartDistance();
       void TestMotorSetOffset();
       void TestMotorCompareVal();
       void TestMotorUpPassCount();
       void TestMotorGetPassCount();

       void TestEmergencyLineCheck();
       void TestEmergencyLeftTurn();
       void TestEmergencyRightTurn();

       void assertEquals(bool result,bool retval);
};
#endif

