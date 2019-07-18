#include "LookUpTest.h"

LookUpTest::LookUpTest()
{
    // sensor値
    sd_test[0].distance = {-1,0,1};
    sd_test[0].distance_retval = false;
    sd_test[1].distance = {4,5,6};
    sd_test[1].distance_retval = false;
    sd_test[2].distance = {5,6,7};
    sd_test[2].distance_retval = true;
    sd_test[3].distance = {20,21,22};
    sd_test[3].distance_retval = true;
    sd_test[4].distance = {29,30,31};
    sd_test[4].distance_retval = false;
    sd_test[5].distance = {30,31,32};
    sd_test[5].distance_retval = false;

    // sonar比較
    sc_test[0].stop_distance = STOP_DISTANCE -1;
    sc_test[0].stop_distance_retval = true;
    sc_test[1].stop_distance = STOP_DISTANCE;
    sc_test[1].stop_distance_retval = true;
    sc_test[2].stop_distance = STOP_DISTANCE +1;
    sc_test[2].stop_distance_retval = false;
    sc_test[3].stop_distance = 5;
    sc_test[3].stop_distance_retval = true;
    sc_test[4].stop_distance = 4;
    sc_test[4].stop_distance_retval = false;
    sc_test[5].stop_distance = 30;
    sc_test[5].stop_distance_retval = false;

    // sonarinput
    si_test[0].input_data = STOP_DISTANCE;
    si_test[0].input_data_retval = true;
    si_test[1].input_data = MAX_SONER-1;
    si_test[1].input_data_retval = true;
    si_test[2].input_data = MAX_SONER;
    si_test[2].input_data_retval = true;
    si_test[3].input_data = MAX_SONER+1;
    si_test[3].input_data_retval = false;
    si_test[4].input_data = MIN_SONER-1;
    si_test[4].input_data_retval = false;
    si_test[5].input_data = MAX_SONER;
    si_test[5].input_data_retval = true;
    si_test[6].input_data = MAX_SONER+1;
    si_test[6].input_data_retval = true;

    //tail
    t_test[0].angles = MIN_TARGET -1;
    t_test[0].angles_retval = false;
    t_test[1].angles = MIN_TARGET;
    t_test[1].angles_retval = true;
    t_test[2].angles = MIN_TARGET +1;
    t_test[2].angles_retval = false;
    t_test[3].angles = MAX_TARGET -1;
    t_test[3].angles_retval = false;
    t_test[4].angles = MAX_TARGET;
    t_test[4].angles_retval = true;
    t_test[5].angles = MAX_TARGET +1;
    t_test[5].angles_retval = false;

    // emergencyreflects
    el_test[0].reflects = MIN_REFLRCT-1;
    el_test[0].reflects_retval = false;
    el_test[1].reflects = MIN_REFLRCT;
    el_test[1].reflects_retval = false;
    el_test[2].reflects = MIN_REFLRCT+1;
    el_test[2].reflects_retval = true;
    el_test[3].reflects = MAX_REFLRCT-1;
    el_test[3].reflects_retval = true;
    el_test[4].reflects = MAX_REFLRCT;
    el_test[4].reflects_retval = false;
    el_test[5].reflects = MAX_REFLRCT+1;
    el_test[5].reflects_retval = false;
    
    // emergency left
    elf_test[0].left_turn_deg = {109,-107};
    elf_test[0].left_turn_deg_retval = false;
    elf_test[1].left_turn_deg = {109,-108};
    elf_test[1].left_turn_deg_retval = true;
    elf_test[2].left_turn_deg = {108,-107};
    elf_test[2].left_turn_deg_retval = false;
    elf_test[3].left_turn_deg = {108,-108};
    elf_test[3].left_turn_deg_retval = false;

    // emergency right
    er_test[0].right_turn_deg = {-107,107};
    er_test[0].right_turn_deg_retval = false;
    er_test[1].right_turn_deg = {-107,109};
    er_test[1].right_turn_deg_retval = false;
    er_test[2].right_turn_deg = {-109,107};
    er_test[2].right_turn_deg_retval = false;
    er_test[3].right_turn_deg = {-108,108};
    er_test[3].right_turn_deg_retval = false;
}

void LookUpTest::TestSonarFilterFilterInput()
{
    for (auto i = 0; i < SONAR_DISTANCE; i++)
    {
        SonarFilter::GetInstance()->StbGetDistance(si_test[i].input_data);
        assertEquals(SonarFilter::GetInstance()->FilterInput(),si_test[i].input_data_retval);
    }
    return;
}

void LookUpTest::TestSonarFilterGetAvg(){

    for (auto i = 0; i < SONAR_DISTANCE; i++)
    {
        SonarFilter::GetInstance()->SetAvg(sd_test[i].distance[0],sd_test[i].distance[1],sd_test[i].distance[2]);
        EV3_LOG_DEBUG("SonarDistance %d[cm]",SonarFilter::GetInstance()->GetAvg());
    }
    return;
}

void LookUpTest::TestTailAngleTest()
{
    for(auto i = 0; i< TAIL; i++)
     {
        assertEquals(tctrl.Angle(t_test[i].angles),t_test[i].angles_retval);
     }
}

void LookUpTest::TestTailStageAngleTest()
{ 
    for(auto i = 0; i< TAIL; i++)
     {
        assertEquals(tctrl.Angle(t_test[i].angles),t_test[i].angles_retval);
    }
}

void LookUpTest::TestSonarControlCheckAvg()
{
      for (auto i = 0; i < SONAR_CHECK; i++)
    {
    SonarControl::GetInstance()->SetAvg(sc_test[i].stop_distance);
    assertEquals(SonarControl::GetInstance()->CheckAvg(),sc_test[i].stop_distance_retval);
    }
}

void LookUpTest::TestSonarControlGetAvg()
{      
    for (auto i = 0; i < SONAR_GETAVG; i++)
    {
        EV3_LOG_DEBUG("SonarDistance %d[cm]",SonarControl::GetInstance()->GetAvg());
    }
}

void LookUpTest::TestMotorSetStartDistance()
{
    mctrl.StbSetStartDistance(100.00);
    mctrl.SetStartDistance();
    mctrl.StbSetStartDistance(120.20);
    mctrl.SetStartDistance();
}

void LookUpTest::TestMotorSetOffset()
{
    for (auto i = 0; i < MOTOR; i++)
    {
        mctrl.SetOffset();
    }
}

void LookUpTest::TestMotorCompareVal()
{
for (auto i = 0; i <MOTOR; i++)
    {
        mctrl.CompareVal();
    }
}

void LookUpTest::TestMotorGetPassCount()
{
    for (auto i = 0; i < MOTOR; i++)
    {
        mctrl.UpPassCnt();
    }
}

void LookUpTest::TestEmergencyLeftTurn()
{
    for (auto i = 0; i < LEFTDEG; i++)
    {
        ectrl.StbLeftTurnAngle(elf_test[i].left_turn_deg[0],elf_test[i].left_turn_deg[1]);
        assertEquals(ectrl.LeftTurn(),elf_test[i].left_turn_deg_retval);
    }
}

void LookUpTest::TestEmergencyRightTurn()
{
    for (auto i = 0; i < RIGHTDEG; i++)
    {
        ectrl.StbRightTurnAngle(er_test[i].right_turn_deg[0],er_test[i].right_turn_deg[1]);
        assertEquals(ectrl.LeftTurn(),er_test[i].right_turn_deg_retval);
    }

}

void LookUpTest::TestEmergencyLineCheck()
{
    for (auto i = 0; i < EMERGENCY; i++)
    {
        ectrl.StbGetColor(el_test[i].reflects);
        assertEquals(ectrl.LineCheck(),el_test[i].reflects_retval);
    }
}

void LookUpTest::assertEquals(bool result,bool retval)
{
if(result != retval)
{
    EV3_LOG_DEBUG("ERROR");
}
    return;
}


