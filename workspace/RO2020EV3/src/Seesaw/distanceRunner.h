#pragma once
#include"straightRunner.h"
#include<Steering.h>
#include<Drive.h>
#include"infoDistanceRun.h"
#include<Logger.h>

class distanceRunner{
    public:
        bool run(infoDistanceRun*);
    private:
        float m_startDistance;
    
};