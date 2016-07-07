#ifndef __GL_SUPPORT__
#define __GL_SUPPORT__

#include "OpenGL Library\glew.h"
#include "OpenGL Library\wglew.h"
#include "OpenGL Library\freeglut.h"

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "freeglut.lib")


/*
* Used in Program PIpeline.
* for setting and checking program of pipeline.
*/
typedef struct ShaderSet
{
	GLuint vs_program_id;
	GLuint tcs_program_id;
	GLuint tes_program_id;
	GLuint gs_program_id;
	GLuint cs_program_id;
	GLuint fs_program_id;
}shader_set;


/*
* When using SHADER_TYPE enum, use this typedef in argument.
*/
typedef int SHADER;

/*
* used in Program class.
* for selecting type of shader that contains with array[6].
*/
enum SHADER_TYPE
{
	VERTEX = 0,
	TESS_CONTROL = 1,
	TESS_EVALUATION = 2,
	GEOMETRY = 3,
	COMPUTE = 4,
	FRAGMENT = 5
};

#endif