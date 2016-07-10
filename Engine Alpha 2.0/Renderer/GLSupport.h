#ifndef __GL_SUPPORT__
#define __GL_SUPPORT__

#include "OpenGL Library\glew.h"
#include "OpenGL Library\wglew.h"
#include "OpenGL Library\freeglut.h"

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "freeglut.lib")

#include <string>


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


enum MATRIX_TYPE
{
	MODEL = 0,
	VIEW = 1,
	PROJECTION = 2
};


typedef struct TypeToNameEntry
{
	GLenum type;
	const char* name;
	GLint size;
	GLenum single_type;
}type_to_name_entry;

const type_to_name_entry type_to_name_table[] =
{
	GL_FLOAT,				"float",	1,	GL_FLOAT,
	GL_FLOAT_VEC2,			"vec2",		2,	GL_FLOAT,
	GL_FLOAT_VEC3,			"vec3",		3,	GL_FLOAT,
	GL_FLOAT_VEC4,			"vec4",		4,	GL_FLOAT,
	GL_DOUBLE,				"double",	1,	GL_DOUBLE,
	GL_DOUBLE_VEC2,			"dvec2",	2,	GL_DOUBLE,
	GL_DOUBLE_VEC3,			"dvec3",	3,	GL_DOUBLE,
	GL_DOUBLE_VEC4,			"dvec4",	4,	GL_DOUBLE,
	GL_INT,					"int",		1,	GL_INT,
	GL_INT_VEC2,			"ivec2",	2,	GL_INT,
	GL_INT_VEC3,			"ivec3",	3,	GL_INT,
	GL_INT_VEC4,			"ivec4",	4,	GL_INT,
	GL_UNSIGNED_INT,		"uint",		1,	GL_UNSIGNED_INT,
	GL_UNSIGNED_INT_VEC2,	"uvec2",	2,	GL_UNSIGNED_INT,
	GL_UNSIGNED_INT_VEC3,	"uvec3",	3,	GL_UNSIGNED_INT,
	GL_UNSIGNED_INT_VEC4,	"uvec4",	4,	GL_UNSIGNED_INT,
	GL_BOOL,				"bool",		1,	GL_BOOL,
	GL_BOOL_VEC2,			"bvec2",	2,	GL_BOOL,
	GL_BOOL_VEC3,			"bvec3",	3,	GL_BOOL,
	GL_BOOL_VEC4,			"bvec4",	4,	GL_BOOL,
	GL_NONE,				NULL,		0,	GL_NONE
};


#endif