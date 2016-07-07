
#include "BufferManager.h"
#include "Buffer.h"

#include <assert.h>
#include <algorithm>

BufferManager* BufferManager::create()
{
	BufferManager* buffermanager = new BufferManager();
	if (buffermanager && buffermanager->init())
	{

	}
	else
	{
		SAFE_DELETE(buffermanager)
	}

	return buffermanager;
}

void BufferManager::addBuffer(Buffer* buffer)
{
	assert(buffer != nullptr);

	_bufferlist.push_back(buffer);

}

Buffer* BufferManager::getBuffer(const GLuint buffer_id)
{
	Buffer* target = nullptr;

	std::for_each(_bufferlist.begin(), _bufferlist.end(), [&](Buffer* buffer) {if (buffer->getID() == buffer_id)target = buffer;});

	return target;
}

Buffer* BufferManager::getBuffer(const char* buffer_name)
{
	Buffer* target = nullptr;

	std::for_each(_bufferlist.begin(), _bufferlist.end(), [&](Buffer* buffer) {if (buffer->getName().c_str() == buffer_name)target = buffer;});

	return target;
}

void BufferManager::deleteBuffer(const GLuint buffer_id)
{
	for (auto i = _bufferlist.begin(); i != _bufferlist.end(); i++)
		if ((*i)->getID() == buffer_id)
		{
			Buffer* buffer = (*i);
			_bufferlist.erase(i);

			delete buffer;
			break;
		}
}

void BufferManager::deleteBuffer(const char* buffer_name)
{
	for (auto i = _bufferlist.begin(); i != _bufferlist.end(); i++)
		if ((*i)->getName().c_str() == buffer_name)
		{
			Buffer* buffer = (*i);
			_bufferlist.erase(i);

			delete buffer;
			break;
		}
}

void BufferManager::deleteAllBuffers()
{
	Buffer* buffer;

	while (_bufferlist.empty() == false)
	{
		buffer = _bufferlist.back();
		_bufferlist.pop_back();

		delete buffer;
	}
}

void BufferManager::showBufferIist()
{
	//logger 작성 후 작성
}

BufferManager::~BufferManager()
{
	deleteAllBuffers();
}

BufferManager::BufferManager()
{
	_bufferlist.clear();
}

bool BufferManager::init()
{
	return true;
}