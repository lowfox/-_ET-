#pragma once
#include<Drive.h>
#include<Logger.h>
#include<RyujiEv3.h>
class lineTracer{
    public:
        bool run(int32);
    private:
        int32 m_angle=70;
};