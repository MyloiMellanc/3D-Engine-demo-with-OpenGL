
#include "Buffer.h"

#include <assert.h>

Buffer* Buffer::create(const char* name, const GLenum buffer_type, const GLenum data_type)
{
	GLuint buffer_id;
	glGenBuffers(1, &buffer_id);

	Buffer* buffer = nullptr;

	const int GENERATE_FAILED = 0;

	if (buffer_id != GENERATE_FAILED)
	{
		buffer = new Buffer();

		if (buffer && buffer->init())
		{
			buffer->setID(buffer_id);
			buffer->setName(name);
			buffer->setBufferType(buffer_type);
			buffer->setDataType(data_type);
		}
		else
		{
			glDeleteBuffers(1, &buffer_id);
			SAFE_DELETE(buffer)
		}
	}

	return buffer;
}


void Buffer::showBufferInfo()
{
	//logger 작성 후 작성
}

void Buffer::Bind()
{
	glBindBuffer(_buffer_type, _id);
}


void Buffer::setID(const GLuint id)
{
	assert(id != 0);

	_id = id;
}

void Buffer::setName(const char* name)
{
	assert(name != nullptr);

	_name = name;
}

void Buffer::setBufferType(const GLenum buffer_type)
{
	assert(buffer_type != 0);

	_buffer_type = buffer_type;
}

void Buffer::setDataType(const GLenum data_type)
{
	assert(data_type != 0);

	_data_type = data_type;
}

GLuint Buffer::getID() const
{
	return _id;
}

std::string Buffer::getName() const
{
	return _name;
}

GLenum Buffer::getBufferType() const
{
	return _buffer_type;
}

GLenum Buffer::getDataType() const
{
	return _data_type;
}


Buffer::~Buffer()
{
	GLuint id = getID();
	glDeleteBuffers(1, &id);
}

Buffer::Buffer()
:_id(0)
,_buffer_type(0)
,_data_type(0)
{
	_name.clear();
}

bool Buffer::init()
{
	return true;
}