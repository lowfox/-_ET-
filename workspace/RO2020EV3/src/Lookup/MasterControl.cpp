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
    
    lookuptest.TestSonarFilterGetAvg();
    lookuptest.TestSonarFilterFilterInput();
    lookuptest.TestSonarControlCheckAvg();
    lookuptest.TestSonarControlGetAvg();
    lookuptest.TestTailAngleTest();
    lookuptest.TestTailStageAngleTest();
    
    return true;

    #endif


    if(!phase1.run())
    {
        return false;
    }

    if(!phase2.run())
    {
        return false;
    }

    if(!phase3.run())
    {
        return false;
    }

    return true;
}

MasterControl::~MasterControl()
{
    // シングルトンを解放
    SonarControl::GetInstance()->Destroy();
    SonarFilter::GetInstance()->Destroy();


}