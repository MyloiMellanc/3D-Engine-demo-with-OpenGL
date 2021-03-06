#include "World.h"
#include "Object.h"
#include "Camera.h"
#include "NullCamera.h"
#include "WorldManager.h"
#include "../Support/Macro.h"
#include <assert.h>


int World::WORLD_ID = 0;

World* World::create()
{
	World* world = new World();
	if (world && world->init())
	{
		giveId(world);
	}
	else
	{
		SAFE_DELETE(world)
	}

	return world;
}

void World::setId(int id)
{
	_id = id;
}

void World::giveId(World* world)
{
	WORLD_ID++;
	world->setId(WORLD_ID);
}

int World::getId() const
{
	return _id;
}

void World::addObject(Object* object)
{
	assert(object != nullptr);

	object->setCurrentWorld(this);
	_objectlist.push_back(object);
}

void World::addObjectWithTag(Object* object, const std::string& tag)
{
	assert(object != nullptr);

	object->setTag(tag);
	object->setCurrentWorld(this);
	_objectlist.push_back(object);
}

Object* World::getObjectById(int id)
{
	auto object_iterator = std::find_if(_objectlist.begin(), _objectlist.end(), [&](Object* object) {return object->getId() == id;});

	return *object_iterator;
}

int World::getObjectCount() const
{
	return _objectlist.size();
}

int World::getObjectCountByTag(const std::string& tag) const
{
	int count = 0;
	for (auto i = _objectlist.begin(); i != _objectlist.end(); i++)
	{
		if ((*i)->getTag() == tag)
			count++;
	}

	return count;
}

void World::deleteObject(Object* object)
{
	for (auto i = _objectlist.begin(); i != _objectlist.end(); i++)
	{
		if ((*i) == object)
		{
			_objectlist.erase(i);
			break;
		}
	}
}

void World::deleteObjectById(int id)
{
	for (auto i = _objectlist.begin(); i != _objectlist.end(); i++)
	{
		if ((*i)->getId() == id)
		{
			_objectlist.erase(i);
			break;
		}
	}
}

void World::deleteObjectByTag(const std::string& tag)
{
	//Need more effective algorithm, not for loop.
}

void World::deleteAllObject()
{
	_objectlist.clear();
}

void World::seeAllObject()
{
	std::for_each(_objectlist.begin(), _objectlist.end(), [](Object* object) {object->setVisible(true);});
}

void World::closeAllObject()
{
	std::for_each(_objectlist.begin(), _objectlist.end(), [](Object* object) {object->setVisible(false);});
}

void World::seeObjectById(int id)
{
	std::for_each(_objectlist.begin(), _objectlist.end(), [&](Object* object) {if(object->getId() == id)object->setVisible(true);});
}

void World::closeObjectById(int id)
{
	std::for_each(_objectlist.begin(), _objectlist.end(), [&](Object* object) {if (object->getId() == id)object->setVisible(false);});
}

void World::seeAllObjectByTag(const std::string& tag)
{
	std::for_each(_objectlist.begin(), _objectlist.end(), [&](Object* object) {if (object->getTag() == tag)object->setVisible(true);});
}

void World::closeAllObjectByTag(const std::string& tag)
{
	std::for_each(_objectlist.begin(), _objectlist.end(), [&](Object* object) {if (object->getTag() == tag)object->setVisible(false);});
}

void World::setCamera(Camera* camera)
{
	assert(_pCurrentcamera != nullptr);

	_pCurrentcamera = camera;
	_pCurrentcamera->setCurrentWorld(this);

}

Camera* World::getCamera() const
{
	return _pCurrentcamera;
}

void World::clearCamera()
{
	_pCurrentcamera = _pNullcamera;
}

void World::update(float dt)
{
	_pCurrentcamera->update(dt);

	std::for_each(_objectlist.begin(), _objectlist.end(), [&](Object* object) {object->update(dt);});
}

void World::draw(Renderer* renderer)
{
	_pCurrentcamera->pushMatrix(renderer);

	std::for_each(_objectlist.begin(), _objectlist.end(), [&](Object* object) {object->draw(renderer);});
}

void World::setCurrentWorldManager(WorldManager* worldmanager)
{
	assert(worldmanager != nullptr);

	_pCurrentworldmanager = worldmanager;
}

WorldManager* World::getCurrentWorldManager() const
{
	return _pCurrentworldmanager;
}

World::~World()
{
	if(_pCurrentworldmanager != nullptr)
		_pCurrentworldmanager->deleteWorld(this);

	deleteAllObject();
}

World::World()
: _id(0)
, _pCurrentcamera(nullptr)
, _pCurrentworldmanager(nullptr)
{
	NullCamera* nullcamera = NullCamera::create();
	assert(nullcamera != nullptr);
	_pNullcamera = nullcamera;
	clearCamera();

	_objectlist.clear();
}

bool World::init()
{
	return true;
}


void World::setName(const char* name)
{
	assert(name != nullptr);

	_name = name;
}

std::string World::getName()
{
	return _name;
}