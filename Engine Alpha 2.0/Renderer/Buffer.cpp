
#include "Buffer.h"
#include "BufferData.h"

#include <assert.h>

Buffer* Buffer::create(const char* name, const GLenum buffer_type)
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
		}
		else
		{
			glDeleteBuffers(1, &buffer_id);
			SAFE_DELETE(buffer)
		}
	}

	return buffer;
}


void Buffer::setBufferData(BufferData* bufferdata)
{
	assert(bufferdata != nullptr);

	_buffer_data = bufferdata;
}

BufferData* Buffer::getBufferData()
{
	return _buffer_data;
}

void Buffer::showBufferInfo()
{
	//logger 작성 후 작성
}

void Buffer::Bind()
{
	_buffer_data->Bind(_id);
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

GLuint Buffer::getID() const
{
	return _id;
}

std::string Buffer::getName() const
{
	return _name;
}


Buffer::~Buffer()
{
	GLuint id = getID();
	glDeleteBuffers(1, &id);
	delete _buffer_data;
}

Buffer::Buffer()
:_id(0)
,_buffer_data(nullptr)
{
	_name.clear();
}

bool Buffer::init()
{
	return true;
}