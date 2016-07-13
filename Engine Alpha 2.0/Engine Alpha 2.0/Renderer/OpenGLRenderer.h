#ifndef __OPENGL_RENDERER__
#define __OPENGL_RENDERER__

#include "../Support/Macro.h"
#include "GLSupport.h"
#include "Renderer.h"


class Drawing;

class ShaderManager;
class ProgramManager;
class BufferManager;
class DrawingManager;


class OpenGLRenderer : public Renderer
{
public:
	static OpenGLRenderer* create(int argc, char* argv[], const char* display_name);

	//custom command

	virtual void Reshape(const int width, const int height);
	virtual void Idle();


	//loop command
	virtual void setMainLoop();
	virtual void startMainLoop();


	//for start, and swapbuffer finishing.
	virtual void startRenderingStep();
	virtual void finishRenderingStep();

	//camera command
	virtual void pushMatrix(const int matrix_type, const mat4& matrix);

	//object command
	//pushMatrix는 같이 사용.

	virtual void setDrawing(const int drawing_index);

	virtual void pushUniform(const char* name, const int value);
	virtual void pushUniform(const char* name, const float value);
	virtual void pushUniform(const char* name, const vec2& value);
	virtual void pushUniform(const char* name, const vec3& value);
	virtual void pushUniform(const char* name, const vec4& value);
	virtual void pushUniform(const char* name, const mat4& value);
	/////etc.........

	//선택된 Drawing에다가 model,view,projection matrix 3개 다 집어넣고 드로잉.
	//고로, 이 함수는 3D 전용임, 2D전용 드로잉은 따로 설계할 필요가 있음.
	virtual void draw();


	////////////////////////////////////

	bool initDisplay(const char* display_name);
	bool initOpenGLExtensions();

	void setCurrentDrawing(Drawing* drawing);

	void setDrawingManager(DrawingManager* drawingmanager);
	void setBufferManager(BufferManager* buffermanager);
	void setProgramManager(ProgramManager* programmanager);
	void setShaderManager(ShaderManager* shadermanager);

	Drawing* getCurrentDrawing();

	DrawingManager* getDrawingManager();
	BufferManager* getBufferManager();
	ProgramManager* getProgramManager();
	ShaderManager* getShaderManager();

	mat4 getMatrix(const int matrix_type);

	~OpenGLRenderer();

PROTECT_CONSTRUCTOR_ACCESS:
	OpenGLRenderer();
	virtual bool init(int argc, char* argv[]);

protected:

	GLuint _uniform_location;

private:
	static OpenGLRenderer* _pInstance;

	int _screen_width;
	int _screen_height;
	int _window_width;
	int _window_height;

	mat4 _model_matrix;
	mat4 _view_matrix;
	mat4 _projection_matrix;

	Drawing* _pCurrent_drawing;

	DrawingManager* _pDrawingmanager;
	BufferManager* _pBuffermanager;
	ProgramManager* _pProgrammanager;
	ShaderManager* _pShadermanager;

};



#endif
