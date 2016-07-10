#include "WorldManager.h"
#include "World.h"
#include "NullWorld.h"
#include "../Support/Macro.h"
#include <assert.h>

WorldManager* WorldManager::create()
{
	WorldManager* worldmanager = new WorldManager();
	if (worldmanager && worldmanager->init())
	{

	}
	else
	{
		SAFE_DELETE(worldmanager)
	}

	return worldmanager;
}

void WorldManager::addWorld(World* world)
{
	assert(world != nullptr);

	world->setCurrentWorldManager(this);
	_Worldlist.push_back(world);
}

int WorldManager::findWorldIndex(World* world)
{
	static const int NOT_IN_CONTAINER = -1;

	for (unsigned int i = 0; i < _Worldlist.size(); i++)
	{
		if (_Worldlist.at(i) == world)
			return i;
	}
	
	return NOT_IN_CONTAINER;
}

int WorldManager::findWorldIndexById(int id)
{
	static const int NOT_IN_CONTAINER = -1;

	for (unsigned int i = 0; i < _Worldlist.size(); i++)
	{
		if (_Worldlist.at(i)->getId() == id)
			return i;
	}

	return NOT_IN_CONTAINER;
}

void WorldManager::setCurrentWorld(World* world)
{
	int world_index = findWorldIndex(world);
	int NOT_IN_CONTAINER = -1;

	if (world_index == NOT_IN_CONTAINER)
		return;
	
	_pCurrentworld = world;
	
}

void WorldManager::setCurrentWorldById(int id)
{
	int world_index = findWorldIndexById(id);
	static const int NOT_IN_CONTAINER = -1;

	if (world_index == NOT_IN_CONTAINER)
		return;

	_pCurrentworld = _Worldlist.at(world_index);
}

World* WorldManager::getCurrentWorld() const
{
	return _pCurrentworld;
}


void WorldManager::clearCurrentWorld()
{
	_pCurrentworld = _pNullworld;
}

void WorldManager::deleteWorld(World* world)
{
	for (auto i = _Worldlist.begin(); i != _Worldlist.end(); i++)
	{
		if ((*i) == world)
		{
			if ((*i) == _pCurrentworld)
				clearCurrentWorld();

			_Worldlist.erase(i);			
			break;
		}
	}
}

void WorldManager::deleteWorldById(int id)
{
	for (auto i = _Worldlist.begin(); i != _Worldlist.end(); i++)
	{
		if ((*i)->getId() == id)
		{
			if ((*i) == _pCurrentworld)
				clearCurrentWorld();
			_Worldlist.erase(i);
			break;
		}
	}
}

void WorldManager::update(float dt)
{
	_pCurrentworld->update(dt);
}

void WorldManager::draw(Renderer* renderer)
{
	_pCurrentworld->draw(renderer);
}


WorldManager::~WorldManager()
{
	_Worldlist.clear();

	delete _pNullworld;
}


WorldManager::WorldManager()
{
	_pNullworld = NullWorld::create();
	assert(_pNullworld != nullptr);

	clearCurrentWorld();

	_Worldlist.clear();
}

bool WorldManager::init()
{
	return true;
}

