#include"bodyAngleChangerTest.h"

bool bodyAngleChangerTest::runTest(){
    bodyAngleChanger i_bodyAngleChanger;
    bool retValue;
    if(false != (retValue = i_bodyAngleChanger.run(NULL))){
        EV3_LOG("TEST_ERR : bodyAngleChanger.run(InfoRun*)...InfoRun*=NULL, retValue=%d\n",retValue);
        return false;
    }
    
    return true;
}