#ifndef __SHADER_MANAGER__
#define __SHADER_MANAGER__

#include "../Support/Macro.h"
#include "GLSupport.h"
#include <vector>

class Shader;

/*
* This class manage Shader classes. 
* When creating Program class, it get Shader class in ShaderManager class.
* Variable:
*	Shaderlist vector
*/
class ShaderManager
{
public:
	/*
	* All ShaderManager class must be created by create method only.
	* if init() method is return true, it return ShaderManager pointer.
	*/
	static ShaderManager* create();

	/*
	* Add Shader class to shaderlist vector.
	*
	* assert by (shader != nullptr).
	*/
	void addShader(Shader* shader);

	/*
	* Print infomation of all Shaders in shaderlist vector.
	*/
	void showShaderList();

	/*
	* get Shader class pointer by searching with id of shader.
	* if any shader doesn't matches argument, it return nullptr.
	*/
	Shader* getShader(GLuint shader_id) const;

	/*
	* Searching shader that has equal ID of argument.
	*	delete Shader class in shaderlist vector of this class.
	*	delete Shader object in OpenGL memory (in Shader class).
	*
	* if any shader doesn't matches argument, it return false.
	*/
	bool deleteShader(GLuint shader_id);

	void deleteAllShaders();

	/*
	* Destructor of ShaderManager class.
	* delete all Shader class in shaderlist vector.
	*/
	~ShaderManager();

	/*
	* constructor method is used only in create method.
	* this class must be created by create method only.
	* it initialize variable of this class.
	*/
PROTECT_CONSTRUCTOR_ACCESS:

	/*
	* Constructor of ShaderManager class.
	* it initialize class variable.
	*/
	ShaderManager();

	/*
	* It used in create method for checking success of create method.
	*/
	bool init();

protected:

private:
	/*
	* Vector container which have all types of shader class in this program.
	*/
	std::vector<Shader*> _shaderlist;
};


#endif
