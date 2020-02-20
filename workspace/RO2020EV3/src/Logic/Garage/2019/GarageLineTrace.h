#pragma once
#include <RyujiEv3.h>
#include <Steering.h>
#include <Drive.h>
#include <Logger.h>
class GarageLineTrace{
private:
    TraceColor m_traceColor;
public:
    void configTraceColor(ReadColor color);
    void configTraceAngle(int32 angle);
    void configPID(PID pid);
    bool Drive(int32 speed);
    bool stop();
    GarageLineTrace();
    ~GarageLineTrace();

};