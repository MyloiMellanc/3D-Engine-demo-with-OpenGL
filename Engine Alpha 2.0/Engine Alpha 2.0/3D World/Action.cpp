#include "Action.h"
#include "Object.h"
#include <assert.h>



Action* Action::create()
{
	Action* action = new Action();
	if (action && action->init())
	{

	}
	else
	{
		SAFE_DELETE(action)
	}

	return action;
}


void Action::update(float dt)
{
	if(isRunning())
	{
		if (getElapsedTime() >= getDurationTime() + dt)
		{
			setElapsedTime(getDurationTime());

			setRunning(false);
			setFinished(true);
		}

		setElapsedTime(getDurationTime() + dt);
	}
}


void Action::setTargetObject(Object* target)
{
	assert(target != nullptr);

	_pTarget = target;
}

void Action::setRunning(bool running)
{
	_running = running;
}

void Action::setFinished(bool finished)
{
	_finished = finished;
}

void Action::setDurationTime(float durationtime)
{
	_durationtime = durationtime;
}

void Action::setElapsedTime(float elapsedtime)
{
	_elapsedtime = elapsedtime;
}


Object* Action::getTargetObject() const
{
	return _pTarget;
}

bool Action::isRunning() const
{
	return _running;
}

bool Action::isFinished() const
{
	return _finished;
}

float Action::getDurationTime() const
{
	return _durationtime;
}

float Action::getElapsedTime() const
{
	return _elapsedtime;
}

Action::~Action()
{
	if(_pTarget != nullptr)
		_pTarget->deleteAction(this);
}


Action::Action()
: _pTarget(nullptr)
, _running(false)
, _finished(false)
, _durationtime(0.0)
, _elapsedtime(0.0)
{

}

bool Action::init()
{
	return true;
}




