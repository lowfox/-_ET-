#pragma once
#include"tailPositioner.h"
#include"distanceRunner.h"
#include<Logger.h>
class getUp{
    public:
    bool run(InfoTail*,float);
    private:
    InfoDistanceRun m_getUpRun={-100,0};//-20.0f
     
};