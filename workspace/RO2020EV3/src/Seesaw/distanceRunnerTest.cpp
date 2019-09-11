#include"distanceRunnerTest.h"

bool distanceRunnerTest::test(){
    distanceRunner i_distanceRunner;
    //pwm:-100~100 int32
    //distance:0.5~790.0 flaot
    
    InfoDistanceRun infoDistances[11]={{-101,0.5},{-100,0.5},{0,0.5},{100,0.5},{101,0.5},
                                    {20,-1},{20,0.4},{20,3},{20,790},{20,790.5},{20,791}};

    CaseDistanceRunner caseDistanceRunner[12]={{&infoDistances[0],false},{&infoDistances[1],true},{&infoDistances[2],true},{&infoDistances[3],true},{&infoDistances[4],false},
                                           {&infoDistances[5],false},{&infoDistances[6],false},{&infoDistances[7],true},{&infoDistances[8],true},{&infoDistances[9],false},
                                         {&infoDistances[10],false},{NULL,false}};
    for(int i=0; i<12; i++){
        if(caseDistanceRunner[i].retValue != i_distanceRunner.run(caseDistanceRunner[i].info)){
            //log
            EV3_LOG("TEST_ERR:distanceRunner.run ....i=%d, pwm=%d, distance=%d, ret=%d\n", i, caseDistanceRunner[i].info->pwm, caseDistanceRunner[i].info->distance, caseDistanceRunner[i].retValue);

            return false;
        }
    }

    return true;
}