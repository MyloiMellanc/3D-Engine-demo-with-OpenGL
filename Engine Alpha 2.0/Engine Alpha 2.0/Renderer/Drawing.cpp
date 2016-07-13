
#include "Drawing.h"
#include "VertexArayObject.h"
#include "RenderObject.h"
#include "Buffer.h"

#include <assert.h>
#include <algorithm>

Drawing* Drawing::create()
{
	Drawing* drawing = new Drawing();

	if (drawing && drawing->init())
	{

	}
	else
	{
		SAFE_DELETE(drawing)
	}

	return drawing;
}

bool Drawing::initVertexArrayObject()
{
	_vao = VertexArrayObject::create();

	if (_vao != nullptr)
		return true;
	else
		return false;
}

void Drawing::updateRenderObjectInfo()
{
	updateAttributeInfo();
	updateUniformInfo();
}

void Drawing::updateAttributeInfo()
{
	GLint inputs = 0;
	glGetProgramInterfaceiv(_render_object->getID(), GL_PROGRAM_INPUT, GL_ACTIVE_RESOURCES, &inputs);


	static const GLenum props[] = { GL_TYPE, GL_LOCATION };
	GLint params[2];
	GLchar name[64];

	for (GLint i = 0; i < inputs; i++)
	{
		glGetProgramResourceName(_render_object->getID(), GL_PROGRAM_INPUT, i, sizeof(name), NULL, name);
		glGetProgramResourceiv(_render_object->getID(), GL_PROGRAM_INPUT, i, 2, props, 2, NULL, params);

		attribute_link attr;
		attr.name = name;
		attr.data_type = params[0];
		attr.location = params[1];
		attr.target_buffer = nullptr;

		_attributelist.push_back(attr);
	}

}

void Drawing::updateUniformInfo()
{
	GLint uniforms = 0;
	glGetProgramInterfaceiv(_render_object->getID(), GL_UNIFORM, GL_ACTIVE_RESOURCES, &uniforms);


	static const GLenum props[] = { GL_TYPE, GL_LOCATION };
	GLint params[2];
	GLchar name[64];

	for (GLint i = 0; i < uniforms; i++)
	{
		glGetProgramResourceName(_render_object->getID(), GL_UNIFORM, i, sizeof(name), NULL, name);
		glGetProgramResourceiv(_render_object->getID(), GL_UNIFORM, i, 2, props, 2, NULL, params);

		uniform_variable uniform;
		uniform.name = name;
		uniform.type = params[0];
		uniform.location = params[1];

		_uniformlist.push_back(uniform);
	}
}

void Drawing::bindVAO()
{
	_vao->Bind();
}

void Drawing::unbindVAO()
{
	_vao->unBind();
}

void Drawing::updateVAO()
{
	if (checkAttributeIsAllLinked())
	{
		bindVAO();

		for (auto i = _attributelist.begin(); i != _attributelist.end(); i++)
		{
			GLuint attribute_location = (*i).location;
			Buffer* buffer = (*i).target_buffer;
			GLuint buffer_id = (*i).target_buffer->getID();
			GLint size = getSizeOfType((*i).data_type);
			GLenum single_type = getSingleTypeOfType((*i).data_type);

			glEnableVertexAttribArray(attribute_location);
			buffer->Bind();

			glVertexAttribPointer(attribute_location, size, single_type, GL_FALSE, 0, 0);
			
		}

		unbindVAO();
	}
}

bool Drawing::checkAttributeIsAllLinked()
{
	for (auto i = _attributelist.begin(); i != _attributelist.end(); i++)
		if ((*i).target_buffer == nullptr)
			return false;

	return true;
}

void Drawing::linkBufferToAttribute(Buffer* buffer)
{
	int i = getAttributeIndex(buffer->getName());
	const int FAILED = -1;

	if (i == FAILED)
	{
		//logger Ãâ·Â
		return;
	}
	
	if (_attributelist[i].data_type == buffer->getDataType())
		_attributelist[i].target_buffer = buffer;
}

void Drawing::useRenderObject()
{
	_render_object->useThisRenderObject();
}

void Drawing::draw()
{
	//Override me.
}

int Drawing::getAttributeIndex(const std::string& attribute_name) const
{
	for (int i = 0; i < (int)_attributelist.size(); i++)
	{
		if (_attributelist[i].name == attribute_name)
			return i;
	}

	const int FAILED = -1;
	return FAILED;
}

GLuint Drawing::getUniformLocation(const std::string name) const
{
	GLuint loc = glGetUniformLocation(_render_object->getID(), name.c_str());

	return loc;
}


void Drawing::setName(const char* name)
{
	assert(name != nullptr);

	_name = name;
}

void Drawing::setVAO(VertexArrayObject* vao)
{
	assert(vao != nullptr);

	_vao = vao;
}

void Drawing::setRenderObject(RenderObject* render_object)
{
	assert(render_object != nullptr);

	_render_object = render_object;

	setRenderObjectID(_render_object->getID());
}

void Drawing::setRenderObjectID(GLuint id)
{
	_render_object_id = id;
}


std::string Drawing::getName() const
{
	return _name;
}

VertexArrayObject* Drawing::getVAO() const
{
	return _vao;
}

RenderObject* Drawing::getRenderObject() const
{
	return _render_object;
}

GLuint Drawing::getRenderObjectID() const
{
	return _render_object_id;
}

Drawing::~Drawing()
{
	delete _vao;
}

Drawing::Drawing()
:_vao(nullptr)
, _render_object(nullptr)
, _render_object_id(0)
{
	_name.clear();
	_attributelist.clear();
	_uniformlist.clear();
}

bool Drawing::init()
{
	if (initVertexArrayObject())
		return true;
	else
		return false;
}



const char* Drawing::type_to_name(GLenum type)
{
	for (const type_to_name_entry* ptr = &type_to_name_table[0]; ptr->name != NULL; ptr++)
	{
		if (ptr->type == type)
			return ptr->name;
	}

	return NULL;
}


GLint Drawing::getSizeOfType(GLenum type)
{
	for (const type_to_name_entry* ptr = &type_to_name_table[0]; ptr->name != NULL; ptr++)
	{
		if (ptr->type == type)
			return ptr->size;
	}

	const unsigned int FAILED = 999999;
	return FAILED;
}

GLenum Drawing::getSingleTypeOfType(GLenum type)
{
	for (const type_to_name_entry* ptr = &type_to_name_table[0]; ptr->name != NULL; ptr++)
	{
		if (ptr->type == type)
			return ptr->single_type;
	}

	const unsigned int FAILED = 999999;
	return FAILED;
}


void Drawing::demo()
{
	for (auto i = _attributelist.begin(); i != _attributelist.end(); i++)
	{
		printf("attr %s %d\n", (*i).name.c_str(), (*i).location);
	}

	for (auto i = _uniformlist.begin(); i != _uniformlist.end(); i++)
	{
		printf("uniform %s %d\n", (*i).name.c_str(), (*i).location);
	}
	if (checkAttributeIsAllLinked())
		printf("linked\n");
}