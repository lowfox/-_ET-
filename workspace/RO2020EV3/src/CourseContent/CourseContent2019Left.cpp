#include <CourseContent2019Left.h>

CourseContent2019Left::CourseContent2019Left(void) {
  m_garageParam = new Garage2019Param;
  m_seesawParam = new Seesaw2019Param;
  m_garageLogic = new GarageScene2019Logic(m_garageParam);
  m_seesawLogic = new SeesawScene2019Logic(m_seesawParam);
  m_course.push_back(m_seesawLogic);
  m_course.push_back(m_garageLogic);
}

CourseContent2019Left::~CourseContent2019Left(void) {
  delete m_garageParam;
  delete m_seesawParam;
  delete m_garageLogic;
  delete m_seesawLogic;
}