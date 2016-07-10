#include "ShaderManager.h"
#include "GLSupport.h"
#include "Shader.h"
#include <assert.h>
#include <algorithm>

ShaderManager* ShaderManager::create()
{
	ShaderManager* shadermanager = new ShaderManager();

	if (shadermanager && shadermanager->init())
	{

	}
	else
	{
		SAFE_DELETE(shadermanager)
	}
	return shadermanager;
}

void ShaderManager::addShader(Shader* shader)
{
	assert(shader != nullptr);

	_shaderlist.push_back(shader);
}

void ShaderManager::showShaderList()
{
	// logger 완성후 작성할것.
}

Shader* ShaderManager::getShader(GLuint shader_id) const
{
	Shader* shader = nullptr;
	for (auto i = _shaderlist.begin(); i != _shaderlist.end(); i++)
		if ((*i)->getID() == shader_id)
			shader = *i;

	//std::for_each(_shaderlist.begin(), _shaderlist.end(), [&](Shader* sdr) {if (sdr->getID() == shader_id) shader = sdr;});

	return shader;
}

bool ShaderManager::deleteShader(GLuint shader_id)
{
	for (auto i = _shaderlist.begin(); i != _shaderlist.end(); i++)
		if ((*i)->getID() == shader_id)
		{
			Shader* shader = (*i);
			_shaderlist.erase(i);

			delete shader;
			return true;
		}

	return false;
}

void ShaderManager::deleteAllShaders()
{
	Shader* shader;

	while (_shaderlist.empty() == false)
	{
		shader = _shaderlist.back();
		_shaderlist.pop_back();

		delete shader;
	}
}

ShaderManager::~ShaderManager()
{
	deleteAllShaders();
}

ShaderManager::ShaderManager()
{
	//It doesn't have any class variable to initialize.
}

bool ShaderManager::init()
{
	return true;
}