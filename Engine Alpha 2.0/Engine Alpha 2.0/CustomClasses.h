#ifndef __CUSTOM_CLASSES__
#define __CUSTOM_CLASSES__


#include "Header.h"


class Cube : public Object
{
public:
	vec3 _position;
	

	virtual void update(float dt);
	virtual void draw(Renderer* renderer);

	Cube();
protected:

	virtual bool init();
};





class CubeDrawing : public Drawing
{
public:
	Buffer* _index;
	virtual void draw();
};

#endif
