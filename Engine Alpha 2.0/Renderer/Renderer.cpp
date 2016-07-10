#include "Renderer.h"



void Renderer::Reshape(const int width, const int height)
{
	//Override me.
	(void)width;
	(void)height;
}

void Renderer::Idle()
{
	//Override me.
}

void Renderer::setMainLoop()
{
	//Override me.
}

void Renderer::startMainLoop()
{
	//Override me.
}



void Renderer::startRenderingStep()
{
	//Override me.
}

void Renderer::finishRenderingStep()
{
	//Override me.
}


void Renderer::pushMatrix(const int matrix_type, const mat4& matrix)
{
	//Override me.
	(void)matrix_type;
	(void)matrix;
}


void Renderer::setDrawing(const int drawing_index)
{
	//Override me.
	(void)drawing_index;
}

void Renderer::pushUniform(const char* name, const int value)
{
	//Override me.
	(void)name;
	(void)value;
}

void Renderer::pushUniform(const char* name, const float value)
{
	//Override me.
	(void)name;
	(void)value;
}

void Renderer::pushUniform(const char* name, const vec2& value)
{
	//Override me.
	(void)name;
	(void)value;
}

void Renderer::pushUniform(const char* name, const vec3& value)
{
	//Override me.
	(void)name;
	(void)value;
}

void Renderer::pushUniform(const char* name, const vec4& value)
{
	//Override me.
	(void)name;
	(void)value;
}

void Renderer::pushUniform(const char* name, const mat4& value)
{
	//Override me.
	(void)name;
	(void)value;
}

void Renderer::draw()
{
	//Override me.
}


Renderer::~Renderer()
{
	//Override me.
}

Renderer::Renderer()
{
	//Override me.
}

bool Renderer::init(int argc, char* argv[])
{
	//Override me.
	(void)argc;
	(void)argv;

	return false;
}

