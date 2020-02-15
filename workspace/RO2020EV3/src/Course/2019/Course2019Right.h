#pragma once
#include <Course.h>
#include <ISceneLogic.h>
#include "../../Logic/Garage/2019/GarageScene2019Logic.h"
#include "../../Logic/Seesaw/2019/SeesawScene2019Logic.h"

class Course2019Right : public Course{
    private:
        GarageScene2019Logic* m_garageLogic;
        SeesawScene2019Logic* m_seesawLogic;
    public:
        Course2019Right(void);
        ~Course2019Right(void);
};