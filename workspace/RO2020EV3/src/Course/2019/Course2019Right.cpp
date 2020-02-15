#include "Course2019Right.h"
#include <Logger.h>
#include <Config.h>
#include <vector>

Course2019Right::Course2019Right(void) {
  EV3_LOG_INFO("Course2019Right Start !\n");
  m_garageLogic = new GarageScene2019Logic(GARAGE2019PARAM);
  m_seesawLogic = new SeesawScene2019Logic(SEESAW2019PARAM);
  m_course.push_back(m_seesawLogic);
  m_course.push_back(m_garageLogic);
}

Course2019Right::~Course2019Right(void) {
  EV3_LOG_INFO("Course2019Right End !\n");
  delete m_garageLogic;
  delete m_seesawLogic;
}
