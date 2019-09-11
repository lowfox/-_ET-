#pragma once

#include"angularVelocityDetector.h"
#include<Drive.h>
#include<RyujiEv3.h>
#include<Logger.h>


class braker{

public:
    bool run(void);
private:
    int16 m_stableOffset = 3;
    int m_cnt=0;
    int m_delayCnt=25;

};