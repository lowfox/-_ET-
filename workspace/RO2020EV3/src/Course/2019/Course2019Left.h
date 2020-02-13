#pragma once
#include <Course.h>
#include <vector>
#include <ISceneLogic.h>
#include "../../Logic/Garage/2019/GarageScene2019Logic.h"
#include "../../Logic/Seesaw/2019/SeesawScene2019Logic.h"
#include "../../Param/Garage2019Param.h"
#include "../../Param/Seesaw2019Param.h"

class Course2019Left : public Course{
    private:
        Garage2019Param* m_garageParam;
        Seesaw2019Param* m_seesawParam;
        GarageScene2019Logic* m_garageLogic;
        SeesawScene2019Logic* m_seesawLogic;
        
    public:
        Course2019Left(void);
        ~Course2019Left(void);
};