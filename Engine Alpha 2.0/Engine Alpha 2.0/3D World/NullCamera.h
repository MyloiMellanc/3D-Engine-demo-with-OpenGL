#ifndef __NULL_CAMERA__
#define __NULL_CAMERA__

#include "../Support/Macro.h"
#include "Camera.h"

class Renderer;

class NullCamera : public Camera
{
public:
	static NullCamera* create();

	virtual void update(float dt);
	virtual void draw(Renderer* renderer);
	virtual void pushMatrix(Renderer* renderer);

	~NullCamera();

PROTECT_CONSTRUCTOR_ACCESS:
	NullCamera();
	virtual bool init();

protected:


private:

};


#endif
