#ifndef __RENDERER__
#define __RENDERER__

#include "../Support/Macro.h"
#include "../Support/cgmath.h"




class Renderer
{
public:

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
	//pushMatrix�� Camera�� ���� ���.

	virtual void setDrawing(const int drawing_index);

	virtual void pushUniform(const char* name, const int value);
	virtual void pushUniform(const char* name, const float value);
	virtual void pushUniform(const char* name, const vec2& value);
	virtual void pushUniform(const char* name, const vec3& value);
	virtual void pushUniform(const char* name, const vec4& value);
	virtual void pushUniform(const char* name, const mat4& value);
	/////etc.........

	//���õ� Drawing���ٰ� model,view,projection matrix 3�� �� ����ְ� �����.
	virtual void draw();


	
	~Renderer();

PROTECT_CONSTRUCTOR_ACCESS:

	Renderer();
	virtual bool init(int argc, char* argv[]);


protected:
	

private:

};


#endif
