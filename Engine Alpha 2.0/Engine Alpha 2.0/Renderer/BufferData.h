#ifndef __BUFFER_DATA__
#define __BUFFER_DATA__


#include "../Support/Macro.h"
#include "../Support/cgmath.h"
#include "GLSupport.h"

#include <vector>

class BufferData
{
public:

	virtual void setData(const char* filepath);
	virtual void showBufferDataInfo();

	
	void Bind(GLuint buffer_id);

	void setBufferType(const GLenum buffer_type);
	GLenum getBufferType() const;

	~BufferData();

protected:

	BufferData();
	

private:
	GLenum _buffer_type;

};



class Array_vec4 : public BufferData
{
public:
	static Array_vec4* create(const GLuint buffer_id, const char* filepath);

	virtual void setData(const char* filepath);
	virtual void showBufferDataInfo();

	~Array_vec4();

PROTECT_CONSTRUCTOR_ACCESS:
	Array_vec4();
	bool init();

protected:

private:

	//변경의 여지가 있음. 저장 시켜야만 하는 여부는 하면서 결정.
	std::vector<vec4> _vectorlist;

};



#endif
