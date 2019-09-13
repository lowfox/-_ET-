    #include"lineTracerTest.h"

    bool lineTracerTest::test(){
        //ライントレースのテスト
        CaseLineTracer caseLineTracer[5]={{-101,false},{-100,true},{0,true},{100,true},{101,true}};
        lineTracer i_lineTracer;

        for(int i=0;i<5;i++){
            if(caseLineTracer[i].retValue != i_lineTracer.run(caseLineTracer[i].pwm,90)){
                //log
                EV3_LOG("TEST_ERR:lineTracer.run ...i=%d, pwm=%d, ret=%d\n",i,caseLineTracer[i].pwm,caseLineTracer[i].retValue);
           
                return false;
            }
        }
        return true;
    }