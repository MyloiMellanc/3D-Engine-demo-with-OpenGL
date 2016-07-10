#ifndef __SHADER__
#define __SHADER__

#include "../Support/Macro.h"
#include "GLSupport.h"
#include <string>

class Program;


/*
* This class represent Shader of OpenGL Library.
* but this class just receive and manage id of Shader, real data is in OpenGL memory.
* Variable:
*	ID
*	Name
*	Shader type
*	Current Program
*/
class Shader
{
public:
	/*
	* All Shader class have to be created by this method.
	* -input shader source code by filename, and compile it.
	* -check compile status -
	*		-fail : delete it, and return nullptr.
	*		-success : return Shader class pointer successfully. 
	*/
	static Shader* create(const char* name, const GLenum shader_type, const char* filepath);


	/*
	* Methods used by create method.
	*/
	bool inputShaderSource(const char* filepath);
	bool compileShader();
	bool checkShader();


	/*
	* Methods about creating shader source
	*/
	static char* readShaderSource(const char* filepath);
	static bool checkShader(GLuint shader_id, const char* shader_name);



	/*
	* setter of Shader class.
	*
	* setID method has assert by (id != 0).
	*/
	void setID(const GLuint id);
	void setName(const std::string& name);
	void setShaderType(const GLenum type);
	void setCurrentProgram(Program* program);


	/*
	* getter of Shader class.
	*/
	GLuint getID() const;
	std::string getName() const;
	GLenum getShaderType() const;
	Program* getCurrentProgram() const;


	/*
	* add information of this shader to log by using log macro.
	* it may be printf, or sent log to its own Logger class.
	*/
	void showShaderInfo();


	/*
	* destructor of Shader class.
	* in destructor, it delete shader created in OpenGL memory.
	*/
	~Shader();


	/*
	* constructor method is used only in create method.
	* this class must be created by create method only.
	* it initialize variable of this class.
	*/
PROTECT_CONSTRUCTOR_ACCESS:
	Shader();

	/*
	* init method used in create method.
	* 
	*/
	bool init();

protected:

private:
	/*
	* this ID is same as Shader ID of OpenGL.
	* when shader was successfully created, it copy shader ID to this variable.
	*/
	GLuint _id;

	/*
	* name of Shader class.
	* It used printing shader class in ShaderManager class.
	*/
	std::string _name;

	/*
	* type of shader : vertex, tessellation(control, evaluation), geometry, compute, fragment
	*/
	GLenum _shader_type;


	/*
	* Program class that contain this Shader class(of course, it is same as OpenGL memory).
	*/
	Program* _pCurrent_program;

};


#endif
