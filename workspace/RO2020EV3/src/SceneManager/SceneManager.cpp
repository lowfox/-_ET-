#include <SceneManager.h>
#include <RyujiEv3.h>
#include "../LineTrace/LineTraceScene.h"
#include "../Garage/GarageScene.h"
#include "../Lookup/LookupScene.h"
#include "../Seesaw/SeesawScene.h"

SceneManager::SceneManager()
{
	m_sceneMap.emplace(SceneID::LineTrace,new LineTraceScene(static_cast<ISceneChanger*>(this)));
	m_sceneMap.emplace(SceneID::Garage   ,new GarageScene(static_cast<ISceneChanger*>(this)) );
	m_sceneMap.emplace(SceneID::Lookup   ,new LookupScene(static_cast<ISceneChanger*>(this)) );
	m_sceneMap.emplace(SceneID::Seesaw   ,new SeesawScene(static_cast<ISceneChanger*>(this)) );

	m_scene.scene = m_sceneMap[SceneID::LineTrace];
	m_scene.id    = SceneID::LineTrace;

	m_nextScene.id    = SceneID::LineTrace;
	m_nextScene.scene = m_sceneMap[SceneID::LineTrace];
}

SceneManager::~SceneManager()
{
	for (auto& itr : m_sceneMap)
	{
		delete itr.second;
	}
}

bool SceneManager::init(SceneID startID)
{
	if (isEnable())
	{
		return false;
	}

	m_scene.id = startID;
	m_scene.scene = m_sceneMap[startID];

	m_nextScene.id = startID;
	m_nextScene.scene = m_sceneMap[startID];

	m_isEnable = true;

	return true;
}

bool SceneManager::run()
{
	if (!isEnable())
	{
		return false;
	}

	if (m_scene.id != m_nextScene.id)
	{
		m_scene = m_nextScene;

		if (!m_scene.scene->init())
		{
			return false;
		}
	}

	return m_scene.scene->run();
}

bool SceneManager::change(SceneID nextSceneID)
{
	if (m_scene.id == nextSceneID)
	{
		return false;
	}
	if (nextSceneID == SceneID::End)
	{
		m_isEnable = false;
		return true;
	}

	m_nextScene.id    = nextSceneID;
	m_nextScene.scene = m_sceneMap[nextSceneID];

	return true;
}
