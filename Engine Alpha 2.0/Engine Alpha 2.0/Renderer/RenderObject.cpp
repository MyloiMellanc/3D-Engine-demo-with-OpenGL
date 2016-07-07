
#include "RenderObject.h"
#include <assert.h>


void RenderObject::useThisRenderObject(const shader_set& shaderset)
{
	//Override me.
}

void RenderObject::setID(const GLuint id)
{
	assert(id != 0);

	_id = id;
}

void RenderObject::setName(const char* name)
{
	assert(name != nullptr);

	_name = name;
}

GLuint RenderObject::getID() const
{
	return _id;
}
std::string RenderObject::getName() const
{
	return _name;
}

RenderObject::~RenderObject()
{
	
}

RenderObject::RenderObject()
: _id(0)
{
	_name.clear();
}