#include <Course.h>

bool Course::run(const int* runSceneNo) {
  //実行する要素数分シーンを実行する
  for (int i = 0; i < sizeof(runSceneNo) / sizeof(runSceneNo[0]); i++) {
    m_course[runSceneNo[i]]->init();
    m_course[runSceneNo[i]]->run();
  }
  return 0;
}