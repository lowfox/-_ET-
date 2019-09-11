#pragma once
#include"getUp.h"
#include"braker.h"
#include<RyujiEv3.h>
#include"infoTail.h"
#include"tailPositioner.h"
class bodyAngleChanger{
    public:
    bool run(InfoTail*);
    private:
    int32 m_nowAngle;
};