#pragma once
#include <Course.h>
#include <Config.h>
#include "../../Logic/Garage/2019/GarageScene2019Logic.h"
#include "../../Logic/Seesaw/2019/SeesawScene2019Logic.h"
#include <vector>
#include <Logger.h>
class Course2019Left : public Course{
    private:
        GarageScene2019Logic* m_garageLogic;
        SeesawScene2019Logic* m_seesawLogic;
    public:
        Course2019Left();
        ~Course2019Left();
};