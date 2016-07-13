#include "NullWorld.h"
#include <assert.h>
#include "../Support/Macro.h"

NullWorld* NullWorld::create()
{
	NullWorld* nullworld = new NullWorld();
	if (nullworld && nullworld->init())
	{
		giveId(nullworld);
	}
	else
	{
		SAFE_DELETE(nullworld)
	}

	return nullworld;
}

void NullWorld::update(float dt)
{
	(void)dt;
	//It does nothing.
}

void NullWorld::draw(Renderer* renderer)
{
	(void)renderer;
	//It does nothing.
}


NullWorld::~NullWorld()
{
	
}


NullWorld::NullWorld()
{

}

bool NullWorld::init()
{
	return true;
}