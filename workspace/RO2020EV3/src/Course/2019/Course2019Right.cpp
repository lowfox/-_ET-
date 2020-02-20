#include "Course2019Right.h"
Course2019Right::Course2019Right(void) {
  EV3_LOG_INFO("Course2019Right Start !\n");
  m_calibrationLogic = new CalibrationScene2019Logic(CALIBRATION2019PARAM);
  m_garageLogic      = new GarageScene2019Logic(GARAGE2019PARAM);
  m_seesawLogic      = new SeesawScene2019Logic(SEESAW2019PARAM);
  m_course.push_back(m_calibrationLogic);
  m_course.push_back(m_seesawLogic);
  m_course.push_back(m_garageLogic);
}

Course2019Right::~Course2019Right(void) {
  EV3_LOG_INFO("Course2019Right End !\n");
  delete m_garageLogic;
  delete m_seesawLogic;
  delete m_calibrationLogic;
}
