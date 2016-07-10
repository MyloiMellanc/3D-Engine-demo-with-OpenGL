#ifndef __PROGRAM_PIPELINE__
#define __PROGRAM_PIPELINE__

#include "../Support/Macro.h"
#include "GLSupport.h"
#include "RenderObject.h"

#include <vector>

class Program;

/*
* it refers Program Pipeline of OpenGL.
* it set progmram shader by shaderset struct.
* Variable:
*	current shaderset
*	
*/
class ProgramPipeline : public RenderObject
{
public:
	/*
	* Program Pipeline class have to be created by this method.
	* if it failed, return nullptr.
	*/
	static ProgramPipeline* create();


	/*
	* set shaderset to its shaderset struct.
	* and set pipeline program id using OpenGL method.
	*/
	void setShaderSet(const shader_set& shaderset);

	

	/*
	* add information of this shader to log by using log macro.
	* it may be printf, or sent log to its own Logger class.
	*/
	void showUsingShader();
	void showUsingProgramList();


	/*
	* override by RenderObject class.
	* perform glUseProgram method.
	*/
	virtual void useThisRenderObject();
	

	/*
	* Detach(not delete, it just clear programlist vector) all programs.
	* and delete pipeline object in OpenGL memory.
	*/
	~ProgramPipeline();

	/*
	* constructor method is used only in create method.
	* this class must be created by create method only.
	*/
PROTECT_CONSTRUCTOR_ACCESS:

	/*
	* Initialize shaderset, programlist.
	*/
	ProgramPipeline();

	/*
	* return true.
	*/
	bool init();

protected:


private:

	/*
	* contains id of shaders that are being used in pipeline.
	*/
	shader_set _shaderset;
};


#endif
