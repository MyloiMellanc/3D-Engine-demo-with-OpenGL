#ifndef __DRAWING__
#define __DRAWING__

#include "../Support/Macro.h"
#include "GLSupport.h"
#include "Buffer.h"
#include <string>
#include <vector>


typedef struct AttributeLink
{
	std::string name;
	GLenum data_type;
	GLuint location;
	Buffer* target_buffer;
}attribute_link;


typedef struct UniformVariable
{
	std::string name;
	GLenum type;
	GLuint location;
}uniform_variable;



class RenderObject;
class VertexArrayObject;

class Drawing
{
public:

	static Drawing* create();

	bool initVertexArrayObject();

	void updateRenderObjectInfo();
	void updateAttributeInfo();
	void updateUniformInfo();

	void bindVAO();
	void unbindVAO();
	void updateVAO();

	bool checkAttributeIsAllLinked();

	void linkBufferToAttribute(Buffer* buffer, const std::string& attribute_name);
	

	void useRenderObject();


	//상속으로 설정.
	virtual void draw();

	

	void setName(const char* name);
	void setVAO(VertexArrayObject* vao);
	void setRenderObject(RenderObject* render_object);
	void setRenderObjectID(GLuint id);

	int getAttributeIndex(const std::string& attribute_name) const;
	GLuint getUniformLocation(const std::string name) const;

	std::string getName() const;
	VertexArrayObject* getVAO() const;
	RenderObject* getRenderObject() const;
	GLuint getRenderObjectID() const;

	~Drawing();

PROTECT_CONSTRUCTOR_ACCESS:
	Drawing();
	bool init();

protected:

	

	/*
	* This three methods are for checking type of attribute and uniform in shader.
	* They use type_to_name_entry in GLSupport.h
	*/

	const char* type_to_name(GLenum type);
	GLint getSizeOfType(GLenum type);
	GLenum getSingleTypeOfType(GLenum type);


private:

	

	std::string _name;

	VertexArrayObject* _vao;

	RenderObject* _render_object;
	GLuint _render_object_id;

	
	std::vector<attribute_link> _attributelist;
	std::vector<uniform_variable> _uniformlist;
};






#endif
