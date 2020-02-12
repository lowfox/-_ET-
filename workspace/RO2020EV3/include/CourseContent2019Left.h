#pragma once
//#include <CourseContent.h>
#include <vector>
#include <ISceneLogic.h>
#include "../src/Logic/GarageScene2019Logic.h"
#include "../src/Logic/SeesawScene2019Logic.h"
#include "../src/Param/Garage2019Param.h"
#include "../src/Param/Seesaw2019Param.h"

class CourseContent2019Left {
    private:
        std::vector<ISceneLogic*> m_course;
        Garage2019Param* m_garageParam;
        Seesaw2019Param* m_seesawParam;
        GarageScene2019Logic* m_garageLogic;
        SeesawScene2019Logic* m_seesawLogic;
        
    public:
        CourseContent2019Left(void);
        ~CourseContent2019Left(void);
        std::vector<ISceneLogic*> getCourse(void){return m_course;}
};