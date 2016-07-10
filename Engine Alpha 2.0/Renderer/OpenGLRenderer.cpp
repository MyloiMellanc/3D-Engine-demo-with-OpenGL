
#include "OpenGLRenderer.h"
#include "Drawing.h"
#include "DrawingManager.h"
#include "BufferManager.h"
#include "ProgramManager.h"
#include "ShaderManager.h"

#include "../Base/Director.h"

#include <assert.h>

OpenGLRenderer* OpenGLRenderer::_pInstance = nullptr;

OpenGLRenderer* OpenGLRenderer::create(int argc, char* argv[], const char* display_name)
{
	if (_pInstance != nullptr)
		return nullptr;

	_pInstance = new OpenGLRenderer();

	if (_pInstance && _pInstance->init(argc, argv) && _pInstance->initDisplay(display_name) && _pInstance->initOpenGLExtensions())
	{
		
	}
	else
	{
		SAFE_DELETE(_pInstance)
	}

	return _pInstance;
}


void OpenGLRenderer::Reshape(const int width, const int height)
{
	_window_width = width;
	_window_height = height;

	glViewport(0, 0, _window_width, _window_height);

	glutPostRedisplay();
}

void OpenGLRenderer::Idle()
{
	glutPostRedisplay();
}


void OpenGLRenderer::setMainLoop()
{
	glutDisplayFunc(Director::Display);
	glutReshapeFunc(Director::Reshape);
	glutKeyboardFunc(Director::Keyboard);
	glutMouseFunc(Director::Mouse);
	glutMotionFunc(Director::Motion);
	glutIdleFunc(Director::Idle);
}

void OpenGLRenderer::startMainLoop()
{
	glutMainLoop();
}


void OpenGLRenderer::startRenderingStep()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
}

void OpenGLRenderer::finishRenderingStep()
{
	glutSwapBuffers();
}


void OpenGLRenderer::pushMatrix(const int matrix_type, const mat4& matrix)
{
	switch (matrix_type)
	{
	case MATRIX_TYPE::MODEL :
		_model_matrix = matrix;
	case MATRIX_TYPE::VIEW :
		_view_matrix = matrix;
	case MATRIX_TYPE::PROJECTION :
		_projection_matrix = matrix;
	}
}


void OpenGLRenderer::setDrawing(const int drawing_index)
{
	_pCurrent_drawing = _pDrawingmanager->getDrawingByIndex(drawing_index);
}

void OpenGLRenderer::pushUniform(const char* name, const int value)
{
	_uniform_location = glGetUniformLocation(_pCurrent_drawing->getRenderObjectID(), name);
	if (_uniform_location > -1)
		glUniform1i(_uniform_location, value);
}

void OpenGLRenderer::pushUniform(const char* name, const float value)
{
	_uniform_location = glGetUniformLocation(_pCurrent_drawing->getRenderObjectID(), name);
	if (_uniform_location > -1)
		glUniform1f(_uniform_location, value);
}


void OpenGLRenderer::pushUniform(const char* name, const vec2& value)
{
	_uniform_location = glGetUniformLocation(_pCurrent_drawing->getRenderObjectID(), name);
	if (_uniform_location > -1)
		glUniform2f(_uniform_location, value.x, value.y);
}

void OpenGLRenderer::pushUniform(const char* name, const vec3& value)
{
	_uniform_location = glGetUniformLocation(_pCurrent_drawing->getRenderObjectID(), name);
	if (_uniform_location > -1)
		glUniform3f(_uniform_location, value.x, value.y, value.z);
}

void OpenGLRenderer::pushUniform(const char* name, const vec4& value)
{
	_uniform_location = glGetUniformLocation(_pCurrent_drawing->getRenderObjectID(), name);
	if (_uniform_location > -1)
		glUniform4f(_uniform_location, value.x, value.y, value.z, value.w);
}

void OpenGLRenderer::pushUniform(const char* name, const mat4& value)
{
	_uniform_location = glGetUniformLocation(_pCurrent_drawing->getRenderObjectID(), name);
	if (_uniform_location > -1)
		glUniformMatrix4fv(_uniform_location, 1, GL_TRUE, value);
}

void OpenGLRenderer::draw()
{
	_pCurrent_drawing->draw();
}



bool OpenGLRenderer::initDisplay(const char* display_name)
{
	_screen_width = glutGet(GLUT_SCREEN_WIDTH);
	_screen_height = glutGet(GLUT_SCREEN_HEIGHT);
	_window_width = 1280;
	_window_height = 720;

	glutInitWindowSize(_window_width, _window_height);
	
	int window_position_x = (int)((_screen_width - _window_width) / 2);
	int window_position_y = (int)((_screen_height - _window_height) / 2);

	glutInitWindowPosition(window_position_x, window_position_y);

	glutCreateWindow(display_name);

	return true;
}

bool OpenGLRenderer::initOpenGLExtensions()
{
	// get the full path of the current executable and change the working directory
	char moduleFilePath[_MAX_PATH]; 
	GetModuleFileNameA(0, moduleFilePath, _MAX_PATH);

	char drive[_MAX_DRIVE], dir[_MAX_DIR], fname[_MAX_FNAME], ext[_MAX_EXT];
	_splitpath_s(moduleFilePath, drive, _MAX_DRIVE, dir, _MAX_DIR, fname, _MAX_FNAME, ext, _MAX_EXT);

	char moduleDir[_MAX_PATH]; sprintf_s(moduleDir, "%s%s", drive, dir);
	SetCurrentDirectoryA(moduleDir);

	// load and register GL extensions using GLEW
	int e; if ((e = glewInit()) != GLEW_OK) { printf("Failed to init GLEW\nError: %s\n", glewGetErrorString(e)); return false; }

	// check GL version
	int verMajor; glGetIntegerv(GL_MAJOR_VERSION, &verMajor); // major = 3
	int verMinor; glGetIntegerv(GL_MINOR_VERSION, &verMinor); // minor = 2
	while (verMinor>10) verMinor /= 10;
	printf("GL: Using OpenGL %d.%d", verMajor, verMinor);
	int version = verMajor * 10 + verMinor;

	// check GLSL version
	const char* strGLSLver = (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);
	if (strGLSLver == NULL) printf("Warning: Unable to get glGetString(GL_SHADING_LANGUAGE_VERSION)\n");
	float GLSLversion = strGLSLver ? float(atof(strGLSLver)) : 0.0f;
	if (GLSLversion < 1.1f) { printf("GLSL %.1f not supports shader programs. Please update your platform\n", GLSLversion); return false; }
	printf(" and GLSL %.1f\n\n", GLSLversion);

	// check supported extensions
	#define CHECK_EXTENSION(ext) if(!glewGetExtension("GL_ARB_"#ext)){ printf( "-------------------------\nGLEW: GL_ARB_" #ext " not supported.\n" ); return false; }
	CHECK_EXTENSION(shading_language_100);	// check your platform supports GLSL
	CHECK_EXTENSION(vertex_buffer_object);	// BindBuffers, DeleteBuffers, GenBuffers, IsBuffer, BufferData, BufferSubData, GenBufferSubData, ...
	CHECK_EXTENSION(vertex_shader);			// functions related to vertex shaders
	CHECK_EXTENSION(fragment_shader);			// functions related to fragment shaders
	CHECK_EXTENSION(shader_objects);			// functions related to program and shaders
	#undef CHECK_EXTENSION

	return true;
}

void OpenGLRenderer::setCurrentDrawing(Drawing* drawing)
{
	assert(drawing != nullptr);

	_pCurrent_drawing = drawing;
}

void OpenGLRenderer::setDrawingManager(DrawingManager* drawingmanager)
{
	assert(drawingmanager != nullptr);

	_pDrawingmanager = drawingmanager;
}

void OpenGLRenderer::setBufferManager(BufferManager* buffermanager)
{
	assert(buffermanager != nullptr);

	_pBuffermanager = buffermanager;
}

void OpenGLRenderer::setProgramManager(ProgramManager* programmanager)
{
	assert(programmanager != nullptr);

	_pProgrammanager = programmanager;
}

void OpenGLRenderer::setShaderManager(ShaderManager* shadermanager)
{
	assert(shadermanager != nullptr);

	_pShadermanager = shadermanager;
}

Drawing* OpenGLRenderer::getCurrentDrawing()
{
	return _pCurrent_drawing;
}

DrawingManager* OpenGLRenderer::getDrawingManager()
{
	return _pDrawingmanager;
}

BufferManager* OpenGLRenderer::getBufferManager()
{
	return _pBuffermanager;
}

ProgramManager* OpenGLRenderer::getProgramManager()
{
	return _pProgrammanager;
}

ShaderManager* OpenGLRenderer::getShaderManager()
{
	return _pShadermanager;
}

mat4 OpenGLRenderer::getMatrix(const int matrix_type)
{
	switch (matrix_type)
	{
	case MATRIX_TYPE::MODEL :
		return _model_matrix;
		break;
	case MATRIX_TYPE::VIEW :
		return _view_matrix;
		break;
	case MATRIX_TYPE::PROJECTION :
		return _projection_matrix;
		break;
	}

	assert(!"Failed to get available Matrix - receive wrong matrix_type argument.\n");

	//this return is mean FAILED.
	return _model_matrix;
}

OpenGLRenderer::~OpenGLRenderer()
{
	delete _pDrawingmanager;
	delete _pBuffermanager;
	delete _pProgrammanager;
	delete _pShadermanager;
}


OpenGLRenderer::OpenGLRenderer()
:_uniform_location(-1)
,_screen_width(0)
,_screen_height(0)
,_window_width(0)
,_window_height(0)
,_pCurrent_drawing(nullptr)
,_pDrawingmanager(nullptr)
,_pBuffermanager(nullptr)
,_pProgrammanager(nullptr)
,_pShadermanager(nullptr)
{
	_model_matrix = mat4();
	_view_matrix = mat4();
	_projection_matrix = mat4();
}

bool OpenGLRenderer::init(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	return true;
}


