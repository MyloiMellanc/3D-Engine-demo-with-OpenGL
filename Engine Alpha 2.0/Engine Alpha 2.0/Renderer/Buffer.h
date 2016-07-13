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
	static Buffer* create(const char* name, const GLenum buffer_type, const GLenum data_type);
	

	void showBufferInfo();

	void Bind();


	void setID(const GLuint id);
	void setName(const char* name);
	void setBufferType(const GLenum buffer_type);
	void setDataType(const GLenum data_type);
	

	GLuint getID() const;
	std::string getName() const;
	GLenum getBufferType() const;
	GLenum getDataType() const;
	

	~Buffer();
	
PROTECT_CONSTRUCTOR_ACCESS:
	Buffer();
	bool init();

protected:

private:
	
	GLuint _id;

	std::string _name;

	GLenum _buffer_type;
	GLenum _data_type;

};

#endif
