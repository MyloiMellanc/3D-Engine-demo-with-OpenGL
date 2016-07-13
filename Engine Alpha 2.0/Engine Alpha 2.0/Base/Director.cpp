#include "Director.h"
#include "../3D World/WorldManager.h"
#include "../3D World/World.h"
#include "../3D World/Camera.h"
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
	Render();
}

void Director::Reshape(int width, int height)
{
	float aspect_ratio = (float)width / (float)height;

	////////////////////////////////////////////////
	// 제발 고쳐줘..................................이 루프는 디렉터에 있으면 안된다.
	////////////////////////////////////////////////
	_pWorldmanager->getCurrentWorld()->getCamera()->setAspectRatio(aspect_ratio);
	

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
	_pRenderer->startRenderingStep();

	_pWorldmanager->draw(_pRenderer);
	//_pLayermanager->draw(_pRenderer);

	_pRenderer->finishRenderingStep();
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

Renderer* Director::getRenderer() 
{
	return _pRenderer;
}

WorldManager* Director::getWorldManager() 
{
	return _pWorldmanager;
}

LayerManager* Director::getLayerManager() 
{
	return _pLayermanager;
}

Director::~Director()
{
	//delete renderer, world and layer manager if they are not static object.
}


Director::Director()
{
	
}

bool Director::init()
{
	return true;
}

