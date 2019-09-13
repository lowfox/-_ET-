#pragma once
#include"seesawRunner.h"
#include"angleDetector.h"
#include"infoTail.h"
#include"getUp.h"
#include"braker.h"
#include"distanceRunner.h"
#include"infoDistanceRun.h"

class seesawDouble{
    public:
        bool run(void);
    private:
        //InfoTail m_lineTraceTail={99,20,true};
        //int16 m_onSeesawTargetValue=40;
        InfoDistanceRun m_twiceForwardRun={-7,-30.0f};
};