#include "Object.h"
#include "Action.h"
#include "World.h"
#include "../Support/Macro.h"
#include <assert.h>

int Object::OBJECT_ID = 0;


Object* Object::create()
{
	Object* object = new Object();
	if (object && object->init())
	{
		giveId(object);
	}
	else
	{
		SAFE_DELETE(object)
	}

	return object;
}

void Object::giveId(Object* object)
{
	OBJECT_ID++;
	object->setId(OBJECT_ID);
}

void Object::setId(int id)
{
	_id = id;
}

void Object::setTag(const std::string& tag)
{
	_tag = tag;
}

void Object::setVisible(bool visible)
{
	_visible = visible;
}

void Object::setPosition(const vec3& pos)
{
	//Override me.
}

void Object::MovePosition(const vec3& pos)
{
	//Override me
}

//void Object::setRotation(? ? ? ? )

//void Object::moveRotation(? ? ? ? )

void Object::setScale(const scale& volume)
{
	//Override me.
}

void Object::moveScale(const scale& volume)
{
	//Override me.
}

int Object::getId() const
{
	return _id;
}

std::string Object::getTag() const
{
	return _tag;
}

bool Object::isVisible() const
{
	return _visible;
}

vec3 Object::getPosition() const
{
	//Override me.
	return vec3(0, 0, 0);
}

//virtual ? ? ? getRotation() const;

scale Object::getScale() const
{
	//Override me.
	return scale(0, 0, 0);
}

void Object::update(float dt)
{
	ActionUpdate(dt);

	//Override me.
}

void Object::draw(Renderer* renderer)
{
	(void)renderer;
	//Override me.
}


void Object::addAction(Action* action, bool running)
{
	assert(action != nullptr);
	
	action->setRunning(running);
	action->setTargetObject(this);
	_actionlist.push_back(action);
}

void Object::runAllAction()
{
	std::for_each(_actionlist.begin(), _actionlist.end(), [](Action* action) {action->setRunning(true);});
}

void Object::stopAllAction()
{
	std::for_each(_actionlist.begin(), _actionlist.end(), [](Action* action) {action->setRunning(false);});
}

void Object::deleteAction(Action* action)
{
	_actionlist.remove(action);
}

void Object::deleteAllAction()
{
	_actionlist.clear();
}

void Object::setCurrentWorld(World* world)
{
	_pCurrentworld = world;
}

World* Object::getCurrentWorld() const
{
	return _pCurrentworld;
}



Object::~Object()
{
	deleteAllAction();

	if(_pCurrentworld != nullptr)
		_pCurrentworld->deleteObject(this);
}

Object::Object()
: _id(0)
, _visible(true)
, _pCurrentworld(nullptr)
{
	_tag.clear();
	_actionlist.clear();
}

bool Object::init()
{
	return true;
}

void Object::ActionUpdate(float dt)
{
	std::for_each(_actionlist.begin(), _actionlist.end(), [&](Action* action) {action->update(dt);});
}