
#include "Program.h"

#include "RenderObject.h"
#include "Shader.h"
#include "ShaderManager.h"

#include "../Support/Macro.h"
#include <assert.h>

Program* Program::create(const char* name)
{
	GLuint id = glCreateProgram();
	if (id == 0)
		return nullptr;

	Program* program = new Program();
	if (program && program->init())
	{
		program->setID(id);
		program->setName(name);
	}
	else
	{
		SAFE_DELETE(program);
		glDeleteProgram(id);
		return nullptr;
	}

	return program;
}


void Program::addShader(const SHADER shader_type, Shader* shader)
{
	assert(shader != nullptr);

	if (_shaders[shader_type] == nullptr)
	{
		glAttachShader(getID(), shader->getID());
		//쉐이더 어태치 성공여부 확인 후 (추후 적용 바람)
		_shaders[shader_type] = shader;
	}
	else
	{
		//이미 존재 로깅
		return;
	}
}

void Program::Link(const bool separable)
{
	glProgramParameteri(getID(), GL_PROGRAM_SEPARABLE, separable);
	glLinkProgram(getID());

	setSeparable(separable);
	setLinked(true);
}

void Program::detachShader(const SHADER shader_type)
{
	if (isLinked() == true)
	{
		//이미 링크되었습니다. 로그
		return;
	}

	if (_shaders[shader_type] != nullptr)
	{
		glDetachShader(getID(), _shaders[shader_type]->getID());
		_shaders[shader_type] = nullptr;
	}
	else
	{
		//실패 로그(해당 쉐이더가 nullptr)출력
	}
}

bool Program::checkProgram()
{
	GLuint programID = getID();
	
	static const int MAX_LOG_LENGTH = 1024;
	static char msg[MAX_LOG_LENGTH] = { NULL };
	GLint programInfoLogLength;
	bool bLogExists = false;

	glGetProgramInfoLog(programID, MAX_LOG_LENGTH, &programInfoLogLength, msg);
	if (bLogExists = (programInfoLogLength>1 && programInfoLogLength <= MAX_LOG_LENGTH))
		printf("[Program Log - ID : %u]\n%s\n",programID, msg);

	GLint programLinkStatus; 
	glGetProgramiv(programID, GL_LINK_STATUS, &programLinkStatus);
	if (programLinkStatus != GL_TRUE) 
	{ 
		glDeleteProgram(programID); 
		return false; 
	}

	glValidateProgram(programID);
	glGetProgramInfoLog(programID, MAX_LOG_LENGTH, &programInfoLogLength, msg);
	if (bLogExists = (programInfoLogLength>1 && programInfoLogLength <= MAX_LOG_LENGTH))
		printf("[Program Log - ID : %u]\n%s\n",programID, msg);

	GLint programValidateStatus; glGetProgramiv(programID, GL_VALIDATE_STATUS, &programValidateStatus);
	if (programValidateStatus != GL_TRUE) 
	{ 
		glDeleteProgram(programID); 
		return false; 
	}

	return true;

}

void Program::showProgramInfo()
{
	//logger 후에 작성
}

void Program::showShaderInfo()
{
	//logger 후에 작성
}

void Program::setSeparable(const bool separable)
{
	_separable = separable;
}

void Program::setLinked(const bool linked)
{
	_linked = linked;
}

Shader* Program::getShader(const SHADER shader_type) const
{
	return _shaders[shader_type];
}

bool Program::isSeparable() const
{
	return _separable;
}

bool Program::isLinked() const
{
	return _linked;
}

void Program::useThisRenderObject()
{
	glUseProgram(getID());
}


Program::~Program()
{
	detachShader(SHADER_TYPE::VERTEX);
	detachShader(SHADER_TYPE::TESS_CONTROL);
	detachShader(SHADER_TYPE::TESS_EVALUATION);
	detachShader(SHADER_TYPE::GEOMETRY);
	detachShader(SHADER_TYPE::COMPUTE);
	detachShader(SHADER_TYPE::FRAGMENT);

	glDeleteProgram(getID());
}

Program::Program()
:_linked(false)
, _separable(false)
{
	const int shader_count = 6;
	for (int i = 0; i < shader_count; i++)
		_shaders[i] = nullptr;
}

bool Program::init()
{
	return true;
}

