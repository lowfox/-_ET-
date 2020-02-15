#include "Course2019Left.h"
#include <Logger.h>
#include "../../Param/Seesaw2019Param.h"
#include "../../Param/Garage2019Param.h"

Course2019Left::Course2019Left(void) {
  EV3_LOG_INFO("Course2019Left Start !\n");
  m_garageLogic =
      new GarageScene2019Logic(ParamGarage2019::garage2019Param.pGrageParam);
  m_seesawLogic =
      new SeesawScene2019Logic(ParamSeesaw2019::seesaw2020Param.pSeesawParam);
  m_course.push_back(m_seesawLogic);
  m_course.push_back(m_garageLogic);
}

Course2019Left::~Course2019Left(void) {
  EV3_LOG_INFO("Course2019Left End !\n");
  delete m_garageLogic;
  delete m_seesawLogic;
}
