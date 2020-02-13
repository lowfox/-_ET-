#pragma once
#include <ICourse.h>
#include <vector>
#include <ISceneLogic.h>
#include "../src/Logic/GarageScene2019Logic.h"
#include "../src/Logic/SeesawScene2019Logic.h"
#include "../src/Param/Garage2019Param.h"
#include "../src/Param/Seesaw2019Param.h"

class Course2019Left : public ICourse{
    private:
        Garage2019Param* m_garageParam;
        Seesaw2019Param* m_seesawParam;
        GarageScene2019Logic* m_garageLogic;
        SeesawScene2019Logic* m_seesawLogic;
        
    public:
        Course2019Left(void);
        ~Course2019Left(void);
        bool init(const int* runSceneNo) override;
        bool run(void) override;
};