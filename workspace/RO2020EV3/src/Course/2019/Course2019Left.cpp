#include "Course2019Left.h"
#include <Logger.h>

Course2019Left::Course2019Left(void) {
  EV3_LOG_INFO("Course2019Left Start !\n");
  m_garageParam = &ParamGarage2019::garage2020Param;
  m_seesawParam = new Seesaw2019Param;
  m_garageLogic = new GarageScene2019Logic(m_garageParam);
  m_seesawLogic = new SeesawScene2019Logic(m_seesawParam);
  m_course.push_back(m_seesawLogic);
  m_course.push_back(m_garageLogic);
}

Course2019Left::~Course2019Left(void) {
  EV3_LOG_INFO("Course2019Left End !\n");
  delete m_seesawParam;
  delete m_garageLogic;
  delete m_seesawLogic;
}
