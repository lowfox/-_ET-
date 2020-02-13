#include <Course.h>
#include <Logger.h>
bool Course::run(const int* runSceneNo) {
  EV3_LOG_DEBUG("Course.run start !");
  //実行する要素数分シーンを実行する
  // TODO：コース内の要素数と、指定実行シーンの要素数があってない場合false返す。
  for (int i = 0; i < sizeof(runSceneNo) / sizeof(runSceneNo[0]); i++) {
    m_course[runSceneNo[i]]->init();
    m_course[runSceneNo[i]]->run();
  }
  return true;
}