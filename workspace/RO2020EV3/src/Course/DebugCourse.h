#pragma once
#include <RyujiEv3.h>
#include <Course.h>
#include "../Logic/Debug/DebugScene.h"
#include "../Logic/Calibration/2019/CalibrationScene2019Logic.h"
#include "../Logic/Garage/2019/GarageScene2019Logic.h"
#include "../Param/Calibration2019Param.h"
#include "../Param/Garage2019Param.h"
#include <Config.h>
#include <Detect.h>
#include <Logger.h>
class DebugCourse : public Course{
    private:
    CalibrationScene2019Logic* m_calibrationScene;
    DebugScene* m_debugScene;
    GarageScene2019Logic* m_garageScene;
    public:
    DebugCourse();
    ~DebugCourse();

};