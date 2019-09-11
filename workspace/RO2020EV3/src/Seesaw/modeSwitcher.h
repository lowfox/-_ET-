#pragma once

#include<Steering.h>
#include"distanceRunner.h"
#include"tailPositioner.h"
#include"infoTail.h"
#include"infoDistanceRun.h"
#include<Drive.h>
#include"braker.h"
class  modeSwitcher
{

public:
    bool run(void);
private:
    /* data */
    InfoTail m_initTail = {90,70,true};
    infoDistanceRun m_modeSwitchRun1 = {6,40.0f};
    infoDistanceRun m_modeSwitchRun2 = {3,20.0f};
    InfoTail m_asobiHoseiTail = {-20,10,false};
     InfoTail m_asobiNoTail = {0,10,true};
 
};



