#ifndef __NULL_WORLD__
#define __NULL_WORLD__

#include "World.h"
#include "../Support/Macro.h"

class Renderer;

class NullWorld : public World
{
public:
	static NullWorld* create();

	virtual void update(float dt);
	virtual void draw(Renderer* renderer);


	~NullWorld();

PROTECT_CONSTRUCTOR_ACCESS:
	NullWorld();
	virtual bool init();

private:


};

#endif
