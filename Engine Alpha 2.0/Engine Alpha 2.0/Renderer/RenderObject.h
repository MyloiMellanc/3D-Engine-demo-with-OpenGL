#ifndef __RENDER_OBJECT__
#define __RENDER_OBJECT__

#include "GLSupport.h"
#include "../Support/Macro.h"
#include <string>


/*
* RenderObject referenced by Program, ProgramPipeline class.
* 
* It manage id, name of program and pipeline.
* when perform rendering, it send shaderset to pipeline(it doesn't affect to single program).
* Variable:
*	ID
*	Name
*/
class RenderObject
{
public:
	/*
	* it is used when perform rendering.
	* it send shaderset to pipeline.
	* shaderset argument doesn't affect to single program.
	*/
	virtual void useThisRenderObject();

	/*
	* setter of id, name.
	* 
	* it checks id by assert (id != 0). ( ID with zero value means error in OpenGL).
	* it checks name by assert (name != nullptr).
	*/
	void setID(const GLuint id);
	void setName(const char* name);

	/*
	* getter of id, name.
	*/
	GLuint getID() const;
	std::string getName() const;

	/*
	* destructor of RenderObject class.
	*/
	~RenderObject();

PROTECT_CONSTRUCTOR_ACCESS:
	/*
	* Initialize id(to 0), name.
	*/
	RenderObject();

protected:
	/*
	* id of Rendering Object (Program, ProgramPipeline).
	* it is used both of RenderObject class and program object of OpenGL memory.
	*/
	GLuint _id;

	/*
	* name of RenderObject class (both Program, ProgramPipeline class use it).
	*/
	std::string _name;
};

#endif
