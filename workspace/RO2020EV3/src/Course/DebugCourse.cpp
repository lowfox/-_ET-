#include "DebugCourse.h"
#include <Drive.h>
DebugCourse::DebugCourse() {
  EV3_LOG_INFO("DebugCourse Constracter!\n");
  Drive::LineTrace::SetSide(Side::Left);
  m_debugScene       = new DebugScene;
  m_calibrationScene = new CalibrationScene2019Logic(CALIBRATION2019PARAM);
  m_garageScene      = new GarageScene2019Logic(GARAGE2019PARAM);
  m_course.push_back(m_calibrationScene);
  m_course.push_back(m_garageScene);
  m_course.push_back(m_debugScene);
}
DebugCourse::~DebugCourse() {
  EV3_LOG_INFO("DebugCourse Destracter!\n");
  delete m_debugScene;
}