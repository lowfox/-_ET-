#pragma once
#include <Course.h>
#include <ISceneLogic.h>
#include <Config.h>
#include "../../Logic/Garage/2019/GarageScene2019Logic.h"
#include "../../Logic/Seesaw/2019/SeesawScene2019Logic.h"
#include "../../Logic/Calibration/2019/CalibrationScene2019Logic.h"
#include <vector>
#include <Logger.h>
class Course2019Right : public Course{
    private:
        GarageScene2019Logic* m_garageLogic;
        SeesawScene2019Logic* m_seesawLogic;
        CalibrationScene2019Logic* m_calibrationLogic;
    public:
        Course2019Right(void);
        ~Course2019Right(void);
};