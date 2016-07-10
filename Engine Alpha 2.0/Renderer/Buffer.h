#ifndef __BUFFER__
#define __BUFFER__

#include "../Support/Macro.h"
#include "GLSupport.h"

#include <string>

class BufferData;

/*
* Buffer class with BufferData.
* it manage id, name, and buffer data.
* Variable
*	ID
*	name
*	Buffer Type
*	Buffer Data pointer
*/
class Buffer
{
public:
	static Buffer* create(const char* name, const GLenum type);
	
	void setBufferData(BufferData* bufferdata);

	BufferData* getBufferData();

	void showBufferInfo();

	void Bind();


	void setID(const GLuint id);
	void setName(const char* name);
	

	GLuint getID() const;
	std::string getName() const;
	

	~Buffer();
	
PROTECT_CONSTRUCTOR_ACCESS:
	Buffer();
	bool init();

protected:

private:
	
	GLuint _id;

	std::string _name;

	BufferData* _buffer_data;


};

#endif
