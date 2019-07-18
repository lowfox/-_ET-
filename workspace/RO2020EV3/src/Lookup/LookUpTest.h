#pragma once
#include"TailControl.h"
#include "MotorControl.h"
#include "SonarControl.h"
#include "SonarFilter.h"
#include "EmergencyControl.h"
#include "../Logger/CLogger.h"
#include "TestData.h"
#include "Debug.h"

#define SONAR_DISTANCE 6
#define SONAR_GETAVG   6
#define SONAR_CHECK    6
#define SONAR_INPUT    6
#define TAIL           6
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

       std::array<int16, SONAR_CHECK> SonarCheckData;
       

public:
  
       LookUpTest();

       void TestSonarFilterFilterInput();
       void TestSonarFilterGetAvg();

       void TestTailAngleTest();
       void TestTailStageAngleTest();

       void TestSonarControlCheckAvg();
       void TestSonarControlGetAvg();
       
       void TestMotorSetStartDistance();
       void TestMotorSetOffset();
       void TestMotorCompareVal();
       void TestMotorGetPassCount();

       void TestEmergencyLineCheck();
       void TestEmergencyLeftTurn();
       void TestEmergencyRightTurn();

       void assertEquals(bool result,bool retval);
};


