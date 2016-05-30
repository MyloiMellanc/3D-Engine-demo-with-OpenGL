#include "Director.h"
#include "../3D World/WorldManager.h"
#include "../Renderer/Renderer.h"
#include "../Support/Macro.h"
#include <assert.h>

Director* Director::_pInstance = nullptr;
Renderer* Director::_pRenderer = nullptr;
WorldManager* Director::_pWorldmanager = nullptr;
LayerManager* Director::_pLayermanager = nullptr;


Director* Director::getInstance()
{
	if (_pInstance == nullptr)
	{
		_pInstance = new Director();
		if (_pInstance && _pInstance->init())
		{

		}
		else
		{
			SAFE_DELETE(_pInstance)
		}
	}
	
	return _pInstance;
}

void Director::Display()
{
	//Divided update() algorithm.
	//render() once.
}

void Director::Reshape(int width, int height)
{
	_pRenderer->Reshape(width, height);
}

void Director::Keyboard(unsigned char key, int x, int y)
{
	//event, maybe next time.
}

void Director::Mouse(int button, int state, int x, int y)
{
	//event, maybe next time.
}

void Director::Motion(int x, int y)
{
	//event, maybe next time.
}

void Director::Idle()
{
	_pRenderer->Idle();
}

void Director::Render()
{
	_pRenderer->startRendering();

	_pWorldmanager->draw(_pRenderer);
	//_pLayermanager->draw(_pRenderer);

	_pRenderer->finishRendering();
}

void Director::Update(float dt)
{
	_pWorldmanager->update(dt);
	//_pLayermanager->update(dt);
}

void Director::run()
{
	_pRenderer->startMainLoop();
}

void Director::setMainLoop()
{
	_pRenderer->setMainLoop();
}

void Director::end()
{
	exit(0);
}

void Director::setRenderer(Renderer* renderer)
{
	assert(renderer != nullptr);

	_pRenderer = renderer;
}

void Director::setWorldManager(WorldManager* worldmanager)
{
	assert(worldmanager != nullptr);

	_pWorldmanager = worldmanager;
}

void Director::setLayerManager(LayerManager* layermanager)
{
	assert(layermanager != nullptr);

	_pLayermanager = layermanager;
}

Renderer* Director::getRenderer() const
{
	return _pRenderer;
}

WorldManager* Director::getWorldManager() const
{
	return _pWorldmanager;
}

LayerManager* Director::getLayerManager() const
{
	return _pLayermanager;
}

Director::~Director()
{
	//delete renderer, world and layer manager if they are not static object.
}


Director::Director()
{
	//Am i initialize static objects in this methods??
}

bool Director::init()
{
	return true;
}

