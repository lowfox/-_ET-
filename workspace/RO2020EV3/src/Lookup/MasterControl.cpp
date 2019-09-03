#include "MasterControl.h"
#include "../../app.h"

#ifdef __LOOKUP_DEBUG__
#include "LookUpTest.h"
#endif

/// Public
bool MasterControl::LookUp()
{
    #ifdef __LOOKUP_DEBUG__

        LookUpTest lookuptest;

        //lookuptest.TestSonarFilterGetAvg();        //OK
        //lookuptest.TestSonarFilterFilterInput();   //OK
        //lookuptest.TestSonarControlCheckAvg();     //OK
        //lookuptest.TestSonarControlGetAvg();       //OK

        //lookuptest.TestTailAngle();                //OK

        //lookuptest.TestTailStageAngle();           //OK

        //lookuptest.TestMotorSetStartDistance();    //OK

        //lookuptest.TestMotorSetOffset();           //OK

        //lookuptest.TestMotorCompareVal();          //OK
        
        //lookuptest.TestMotorGetPassCount();        //OK

        //lookuptest.TestEmergencyLineCheck();       //OK

        //lookuptest.TestEmergencyLeftTurn();        //OK

        //lookuptest.TestEmergencyRightTurn();       //OK
        
    return true;
#else
    EV3_LOG_INFO("DriveStart");

    if(!phase1.run())
    {
        EV3_LOG_INFO("Phase1End");
        return false;
    }

    if(!phase2.run())
    {
        EV3_LOG_INFO("Phase2End");
        return false;
    }

    if(!phase3.run())
    {
        EV3_LOG_INFO("Phase3End");
        return false;
    }
#endif
    return true;
}

MasterControl::~MasterControl()
{
 
    // シングルトンを解放
    SonarControl::GetInstance()->Destroy();
    SonarFilter::GetInstance()->Destroy();
    
}