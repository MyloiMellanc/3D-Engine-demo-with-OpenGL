#ifndef __PROGRAM__
#define __PROGRAM__

#include "../Support/Macro.h"
#include "GLSupport.h"
#include "RenderObject.h"



class Shader;

/*
* it represent Program object of OpenGL memory.
* Variable:
*	in RenderObject class
*		-id(used both class and OpenGL object)
*		-name
*	bool variable
*		-linked
*		_separable
*	6 types of shader class pointer	
*/
class Program : public RenderObject
{
public:
	/*
	* create Program class with name.
	* if it is created successfully, return its pointer value.
	* if failed, return nullptr.
	*/
	static Program* create(const char* name);

	/*
	* add Shader class in this class, and attach it to program in OpenGL memory.
	*		attach shader in program object in OpenGL memory.
	*		add shader class pointer in this class variable.
	*/
	void addShader(const SHADER shader_type, Shader* shader);

	/*
	* perform link attached shaders in program by its id.
	* it set '_linked' bool variable by result of linking process.
	*/
	void Link(const bool separable);

	/*
	* perform detach shader object in program.
	* delete shader class pointer in this class variable.
	*/
	void detachShader(SHADER shader_type);

	/*
	* used in create method of program class.
	* check program status by OpenGL reference and return its valiablity.
	*/
	bool checkProgram();

	/*
	* add information of this program to log by using log macro.
	* it may be printf, or sent log to its own Logger class.
	*/
	void showProgramInfo();

	/*
	* add information of attached shader to log by using log macro.
	* it may be printf, or sent log to its own Logger class.
	*/
	void showShaderInfo();

	/*
	* setter of bool variable of this class.
	*/
	void setSeparable(const bool separable);
	void setLinked(const bool linked);

	/*
	* getter of this class variable.
	*/

	/*
	* if it is not avalilable, it return nullptr.
	*/
	Shader* getShader(const SHADER shader_type) const;
	bool isSeparable() const;
	bool isLinked() const;


	/*
	* perform glUseProgram method, override by RenderObject class.
	* 
	*/
	virtual void useThisRenderObject();


	/*
	* destructor of Program class.
	* detach all attached shaders and delete program object in OpenGL memory.
	*/
	~Program();

	/*
	* constructor method is used only in create method.
	* this class must be created by create method only.
	* it initialize variable of this class.
	*/
PROTECT_CONSTRUCTOR_ACCESS:

	/*
	* Constructor of Program class.
	* it initialize class variable.
	*/
	Program();

	/*
	* It used in create method for checking success of create method.
	*/
	bool init();

protected:

private:
	
	//ID, name of Program is in RenderObject class.

	/*
	* check if this program is linked or not.
	* set by setLinked method.
	*/
	bool _linked;

	/*
	* check if this program is linked with separable or not.
	* if this program is separable, it is used to ProgramPipeline.
	* set by setSeparable method.
	*/
	bool _separable;

	/*
	* pointer of attached Shader class.
	*/
	Shader* _shaders[6];

};


#endif



