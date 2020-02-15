#include "Course2019Left.h"
#include <Logger.h>
#include <Config.h>

Course2019Left::Course2019Left(void) {
  EV3_LOG_INFO("Course2019Left Start !\n");
  m_garageLogic = new GarageScene2019Logic(GARAGE2019PARAM);
  m_seesawLogic = new SeesawScene2019Logic(SEESAW2019PARAM);
  m_course.push_back(m_seesawLogic);
  m_course.push_back(m_garageLogic);
}

Course2019Left::~Course2019Left(void) {
  EV3_LOG_INFO("Course2019Left End !\n");
  delete m_garageLogic;
  delete m_seesawLogic;
}
