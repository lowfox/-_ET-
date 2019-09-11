#pragma once
#include<Drive.h>
#include"straightRunner.h"
#include"../../app.h"
#include<Steering.h>
#include<Logger.h>
#include"braker.h"
#include"seesawGlobal.h"
#include<RyujiEv3.h>

class wheelAligner{
    public:
    
    bool run();
    private:
    int32 m_alignPwm=2;
    float m_detectDistance=25.0f;//8.5‚©‚ç
    float m_nowDistance;
    float m_periodDistance=100;
};
