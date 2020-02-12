#include <Course.h>

Course::Course(std::vector<ISceneLogic*> course) { m_course = course; }

bool Course::init(std::vector<int> runSceneNo) { return 0; }

bool Course::run() {
  m_course[0]->init();
  m_course[0]->run();
  return 0;
}
