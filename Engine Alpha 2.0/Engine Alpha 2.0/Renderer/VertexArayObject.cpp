
#include "VertexArayObject.h"

#include <assert.h>

VertexArrayObject* VertexArrayObject::create()
{
	GLuint vao_id = 0;

	glGenVertexArrays(1, &vao_id);
	if (vao_id == 0)
		return nullptr;

	VertexArrayObject* vao = new VertexArrayObject();
	
	if (vao && vao->init())
	{
		vao->setID(vao_id);
	}
	else
	{
		SAFE_DELETE(vao)
		glDeleteVertexArrays(1, &vao_id);
	}

	return vao;
}

void VertexArrayObject::Bind()
{
	glBindVertexArray(_id);
}

void VertexArrayObject::unBind()
{
	glBindVertexArray(_unbind);
}

void VertexArrayObject::setID(const GLuint id)
{
	assert(id != 0);

	_id = id;
}

GLuint VertexArrayObject::getID() const
{
	return _id;
}


VertexArrayObject::~VertexArrayObject()
{
	GLuint vao_id = getID();

	glDeleteVertexArrays(1, &vao_id);
}


VertexArrayObject::VertexArrayObject()
:_id(0)
{

}

bool VertexArrayObject::init()
{
	return true;
}