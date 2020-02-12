#include <Course2019Left.h>

Course2019Left::Course2019Left(void) {
  m_garageParam = new Garage2019Param;
  m_seesawParam = new Seesaw2019Param;
  m_garageLogic = new GarageScene2019Logic(m_garageParam);
  m_seesawLogic = new SeesawScene2019Logic(m_seesawParam);
  m_course.push_back(m_seesawLogic);
  m_course.push_back(m_garageLogic);
}

Course2019Left::~Course2019Left(void) {
  delete m_garageParam;
  delete m_seesawParam;
  delete m_garageLogic;
  delete m_seesawLogic;
}

bool Course2019Left::init(std::vector<int> runSceneNo) {
  // TODO:ここの実装
  return 0;
}

bool Course2019Left::run(void) {
  for (auto& itr : m_course) {
    itr->init();
    itr->run();
  }
  return 0;
}
