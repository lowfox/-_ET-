#include <Course.h>
bool Course::run(const uint8* runSceneNo) {
  EV3_LOG_DEBUG("Course.run start !");
  //実行する要素数分シーンを実行する
  // TODO：コース内の要素数と、指定実行シーンの要素数があってない場合false返す。
  for (int i = 0; runSceneNo[i] != 255; i++) {
    m_runSceneTotalNum++;
  }
  EV3_LOG_DEBUG("m_course uint8 size=%d\n", sizeof(uint8));
  EV3_LOG_DEBUG("m_course yousosu=%d\n", m_runSceneTotalNum);

  for (uint8 i = 0; i < m_runSceneTotalNum; i++) {
    EV3_LOG_DEBUG("runSceneNo=%d Start !\n", runSceneNo[i]);
    m_course[runSceneNo[i]]->init();
    m_course[runSceneNo[i]]->run();
    EV3_LOG_DEBUG("runSceneNo=%d End !\n", runSceneNo[i]);
  }
  return true;
}