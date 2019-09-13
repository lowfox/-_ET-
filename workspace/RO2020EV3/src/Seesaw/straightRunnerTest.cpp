#include"straightRunnerTest.h"

bool straightRunnerTest::test(){
    straightRunner i_straightRunner;

    CaseStraightRunnerTest caseStraightRunnerTest[]={ {-101,false},{-100,false},{0,false},{100,false},{101,false} };
     for(int i=0; i<5; i++){
        if(caseStraightRunnerTest[i].retValue != i_straightRunner.run(caseStraightRunnerTest[i].pwm)){
            //log
            EV3_LOG("TEST_ERR:straightRunner.run ...i=%d, pwm=%d, ret=%d\n",i,caseStraightRunnerTest[i].pwm,caseStraightRunnerTest[i].retValue);
            return false;
        }
    }
    return true;
}