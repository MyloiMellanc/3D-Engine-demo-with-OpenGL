#ifndef __VERTEX_ARRAY_OBJECT__
#define __VERTEX_ARRAY_OBJECT__

#include "../Support/Macro.h"
#include "GLSupport.h"

class VertexArrayObject
{
public:
	static VertexArrayObject* create();

	void Bind();
	void unBind();

	void setID(const GLuint id);

	GLuint getID() const;

	~VertexArrayObject();

PROTECT_CONSTRUCTOR_ACCESS:
	VertexArrayObject();
	bool init();

protected:


private:
	GLuint _id;

	const GLuint _unbind = 0;
};



#endif
