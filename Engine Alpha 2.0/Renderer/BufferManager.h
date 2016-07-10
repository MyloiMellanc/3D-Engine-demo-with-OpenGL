#ifndef __BUFFER_MANAGER__
#define __BUFFER_MANAGER__

#include "../Support/Macro.h"
#include "GLSupport.h"

#include <vector>

class Buffer;

class BufferManager
{
public:
	static BufferManager* create();

	void addBuffer(Buffer* buffer);

	Buffer* getBuffer(const GLuint buffer_id);
	Buffer* getBuffer(const char* buffer_name);

	void deleteBuffer(const GLuint buffer_id);
	void deleteBuffer(const char* buffer_name);

	void deleteAllBuffers();

	void showBufferIist();



	~BufferManager();

PROTECT_CONSTRUCTOR_ACCESS:
	BufferManager();
	bool init();

protected:

private:
	std::vector<Buffer*> _bufferlist;


};




#endif
