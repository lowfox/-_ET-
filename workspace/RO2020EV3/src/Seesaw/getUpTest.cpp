#include"getUpTest.h"

bool getUpTest::runTest(){
    getUp i_getUp;
    bool retValue;
    if(false != (retValue = i_getUp.run(NULL,-40.0f))){
        EV3_LOG("TEST_ERR : getUp.run(InfoRun*)...InfoRun*=NULL, retValue=%d\n",retValue);
        return false;
    }
    
    return true;
}