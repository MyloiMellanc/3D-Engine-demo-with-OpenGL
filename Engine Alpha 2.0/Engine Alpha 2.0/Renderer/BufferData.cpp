
#include "BufferData.h"
#include <assert.h>

void BufferData::setData(const char* filepath)
{
	//Override me.
}

void BufferData::showBufferDataInfo()
{
	//Override me.
}


void BufferData::Bind(GLuint buffer_id)
{
	glBindBuffer(_buffer_type, buffer_id);
}

void BufferData::setBufferType(const GLenum buffer_type)
{
	assert(buffer_type != 0);

	_buffer_type = buffer_type;
}

GLenum BufferData::getBufferType() const
{
	return _buffer_type;
}

BufferData::~BufferData()
{
	//none.
}

BufferData::BufferData()
:_buffer_type(0)
{
	//none.
}





////////////////////////////////////////// Array_vec4

Array_vec4* Array_vec4::create(const GLuint buffer_id, const char* filepath)
{
	Array_vec4* array_vec4 = new Array_vec4();

	if (array_vec4 && array_vec4->init())
	{
		array_vec4->Bind(buffer_id);
		array_vec4->setData(filepath);
	}
	else
	{
		SAFE_DELETE(array_vec4)
	}

	return array_vec4;
}

void Array_vec4::setData(const char* filepath)
{

}

void Array_vec4::showBufferDataInfo()
{
	//logger 작성 후 작성
}

Array_vec4::~Array_vec4()
{

}

Array_vec4::Array_vec4()
{
	_vectorlist.clear();
}

bool Array_vec4::init()
{
	return true;
}