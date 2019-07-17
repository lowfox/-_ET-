#include "LineTraceScene.h"
#include <Config.h>

LineTraceScene::LineTraceScene(ISceneChanger* sceneChanger) :IScene(sceneChanger)
{
}

bool LineTraceScene::init()
{
	return true;
}

bool LineTraceScene::run()
{

  return change(LINETRACE_NEXT_SCENE);
}