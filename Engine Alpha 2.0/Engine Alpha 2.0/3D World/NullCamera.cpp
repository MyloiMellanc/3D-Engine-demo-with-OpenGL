#include "NullCamera.h"



NullCamera* NullCamera::create()
{
	NullCamera* nullcamera = new NullCamera();
	if (nullcamera && nullcamera->init())
	{

	}
	else
	{
		SAFE_DELETE(nullcamera)
	}

	return nullcamera;
}

void NullCamera::update(float dt)
{
	(void)dt;
	//It does nothing.
}

void NullCamera::draw(Renderer* renderer)
{
	(void)renderer;
	//It does nothing.
}

void NullCamera::pushMatrix(Renderer* renderer)
{
	(void)renderer;
	//It does nothing.
}

NullCamera::~NullCamera()
{

}

NullCamera::NullCamera()
{

}

bool NullCamera::init()
{
	return true;
}