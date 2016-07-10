#include "Shader.h"
#include <assert.h>


Shader* Shader::create(const char* name, const GLenum shader_type, const char* filepath)
{
	
	GLuint id = glCreateShader(shader_type);
	if (id == 0)
		return nullptr;

	Shader* shader = new Shader();
	if (shader && shader->init())
	{
		shader->setID(id);
		shader->setShaderType(shader_type);
		shader->setName(name);
	}
	else
	{
		SAFE_DELETE(shader);
		glDeleteShader(id);
		return nullptr;
	}
	
	
	if (!shader->inputShaderSource(filepath))
	{
		SAFE_DELETE(shader);
		glDeleteShader(id);
		return nullptr;
	}

	if (!shader->compileShader())
	{
		SAFE_DELETE(shader);
		glDeleteShader(id);
		return nullptr;
	}

	return shader;

}


bool Shader::inputShaderSource(const char* filepath)
{
	const char* shader_source = readShaderSource(filepath);
	if(shader_source == NULL)
		return false;

	GLint source_length = strlen(shader_source);
	glShaderSource(_id, 1, &shader_source, &source_length);

	return true;
}


bool Shader::compileShader()
{
	glCompileShader(_id);
	if (!checkShader(_id, _name.c_str()))
		return false;

	return true;
}


char* Shader::readShaderSource(const char* filepath)
{
	//Get full path of shader file.
	char module_file_path[_MAX_PATH];
	GetModuleFileNameA(0, module_file_path, _MAX_PATH);

	char drive[_MAX_DRIVE], dir[_MAX_DIR], fname[_MAX_FNAME], ext[_MAX_EXT];
	_splitpath_s(module_file_path, drive, _MAX_DRIVE, dir, _MAX_DIR, fname, _MAX_FNAME, ext, _MAX_EXT);

	char shader_file_path[_MAX_PATH];
	sprintf_s(shader_file_path, "%s%s%s", drive, dir, filepath);



	//get full path of a shader file.
	FILE* fp;
	fopen_s(&fp, filepath, "rb");

	if (fp == NULL)
	{
		//printf("Unable to open %s\n", shader_file_path);
		return NULL;
	}
	fseek(fp, 0L, SEEK_END);
	size_t fileSize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	char* strShader = (char*)malloc((fileSize + 1) * sizeof(char));
	fread(strShader, sizeof(char), fileSize, fp);
	fclose(fp);

	strShader[fileSize] = NULL;
	return strShader;

}

bool Shader::checkShader(GLuint shader_id, const char* shader_name)
{
	const int MAX_LOG_LENGTH = 1024;
	static char msg[MAX_LOG_LENGTH] = { NULL };
	GLint program_info_log_length;
	bool b_log_exists = false;

	glGetShaderInfoLog(shader_id, MAX_LOG_LENGTH, &program_info_log_length, msg);
	
	b_log_exists = (program_info_log_length > 1 && program_info_log_length <= MAX_LOG_LENGTH);
	if (b_log_exists)
		printf("[Shader Log : %s]\n%s\n", shader_name, msg);

	GLint shader_compile_status;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &shader_compile_status);
	if (shader_compile_status == GL_TRUE)
		return true;

	return false;

}

void Shader::setID(const GLuint id)
{
	assert(id > 0);
	_id = id;
}

void Shader::setName(const std::string& name)
{
	_name = name;
}

void Shader::setShaderType(const GLenum type)
{
	_shader_type = type;
}

void Shader::setCurrentProgram(Program* program)
{
	assert(program != nullptr);
	_pCurrent_program = program;
}

GLuint Shader::getID() const
{
	return _id;
}

std::string Shader::getName() const
{
	return _name;
}

GLenum Shader::getShaderType() const
{
	return _shader_type;
}

Program* Shader::getCurrentProgram() const
{
	return _pCurrent_program;
}


void Shader::showShaderInfo()
{
	//로그 매크로로 정보 출력
	//logger 완성후 작성
}

Shader::~Shader()
{
	//OpenGL 메모리에서 해당 아이디의 쉐이더 제거
	//아이디가 0(쉐이더 없음)일 경우 예외

	if (_id != 0)
		glDeleteShader(_id);

}

Shader::Shader()
: _id(0)
, _shader_type(0)
, _pCurrent_program(nullptr)
{
	_name.clear();
}

bool Shader::init()
{
	return true;
}
