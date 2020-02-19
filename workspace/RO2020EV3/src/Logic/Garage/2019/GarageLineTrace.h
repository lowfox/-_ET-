#pragma once
#include <RyujiEv3.h>
#include <Steering.h>
#include <Drive.h>
class GarageLineTrace{
private:
public:
    void configTraceColor(TraceColor traceColor);
    void configPID(PID pid);
    bool Drive(int32 speed);
    bool stop();
    GarageLineTrace();
    ~GarageLineTrace();

};