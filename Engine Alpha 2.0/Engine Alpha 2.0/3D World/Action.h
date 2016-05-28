#ifndef __ACTION__
#define __ACTION__

#include "../Support/Macro.h"

class Object;

class Action
{
public:
	static Action* create();

	////////command methods
	virtual void update(float dt);

	////////SETTER
	void setTargetObject(Object* target);
	void setRunning(bool running);
	void setFinished(bool finished);
	void setDurationTime(float durationtime);
	void setElapsedTime(float elapsedtime);


	////////GETTER
	Object* getTargetObject() const;
	bool isRunning() const;
	bool isFinished() const;
	float getDurationTime() const;
	float getElapsedTime() const;

	~Action();

PROTECT_CONSTRUCTOR_ACCESS:
	Action();

	virtual bool init();

private:
	Object* _pTarget;

	bool _running;
	bool _finished;

	float _durationtime;
	float _elapsedtime;

};

#endif
