#include <Course.h>
#include <Logger.h>
bool Course::run(const int* runSceneNo) {
  EV3_LOG_DEBUG("Course.run start !");
  //実行する要素数分シーンを実行する
  // TODO：コース内の要素数と、指定実行シーンの要素数があってない場合false返す。
  EV3_LOG_DEBUG("m_course yousosu=%d\n", m_course.size());
  for (unsigned int i = 0; i < m_course.size(); i++) {
    EV3_LOG_DEBUG("runSceneNo=%d Start !\n", runSceneNo[i]);
    m_course[runSceneNo[i]]->init();
    m_course[runSceneNo[i]]->run();
    EV3_LOG_DEBUG("runSceneNo=%d End !\n", runSceneNo[i]);
  }
  return true;
}