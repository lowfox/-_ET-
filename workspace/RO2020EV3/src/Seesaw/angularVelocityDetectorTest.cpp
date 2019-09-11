#include"angularVelocityDetectorTest.h"


bool  angularVelocityDetectorTest::setOffsetTest(){
    angularVelocityDetector i_angularVelocityDetector;
   
    // 角速度検知の閾値設定setOffset()のテスト
    CaseAngVelSetOffset caseAngVelSetOffset[7]={
        {-501,false},{-500,true},{-1,true},{0,true},{1,true},{500,true},{501,false}
    };

    for(int i=0;i<7;i++){
        if(caseAngVelSetOffset[i].retValue != i_angularVelocityDetector.setOffsetValue(caseAngVelSetOffset[i].offsetValue)){
            //rog
            EV3_LOG("TEST_ERR: anglarVelocityDetector.setOffsetTest... i=%d, offset=%d , retValue=%d\n",
            i,caseAngVelSetOffset[i].offsetValue,caseAngVelSetOffset[i].retValue );
            return false;
        }
    }
    return true;
}

bool angularVelocityDetectorTest::detectTest(){
    //test of detect()
    angularVelocityDetector i_angularVelocityDetector;

    int16 offsetValue=120;
    int16 caseAngVelDetect[]={0,50,119,120,121,130};
    bool retDetect[]={false,false,false,true,true};
    for(int i=0;i<6;i++){
        #ifdef TESTMODE
            i_angularVelocityDetector.setTestValue(caseAngVelDetect[i]);
        #endif
        if(retDetect[i] != i_angularVelocityDetector.detect()){
            EV3_LOG("TEST_ERR: anglarVelocityDetector.detect... i=%d, offset=%d , detectValue=%d , retValue=%d\n",
                    i,offsetValue,caseAngVelDetect[i],retDetect[i] );
            return false;
        }

    }
    return true;
}
