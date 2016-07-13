
#include "ProgramManager.h"

#include "Program.h"
#include "ProgramPipeline.h"

#include <assert.h>

ProgramManager* ProgramManager::create()
{
	ProgramManager* manager = new ProgramManager();
	if (manager && manager->init())
	{

	}
	else
	{
		SAFE_DELETE(manager)
	}

	return manager;
}

void ProgramManager::addProgram(Program* program)
{
	assert(program != nullptr);

	_programlist.push_back(program);

}

void ProgramManager::addProgramPipeline(ProgramPipeline* pipeline)
{
	assert(pipeline != nullptr);

	_pipelinelist.push_back(pipeline);
}

Program* ProgramManager::getProgram(const char* program_name)
{
	for (auto i = _programlist.begin(); i != _programlist.end(); i++)
		if ((*i)->getName().c_str() == program_name)
			return (*i);

	return nullptr;
}

Program* ProgramManager::getProgram(const GLuint program_id)
{
	for (auto i = _programlist.begin(); i != _programlist.end(); i++)
		if ((*i)->getID() == program_id)
			return (*i);

	return nullptr;
}

ProgramPipeline* ProgramManager::getProgramPipeline(const char* pipeline_name)
{
	for (auto i = _pipelinelist.begin(); i != _pipelinelist.end(); i++)
		if ((*i)->getName().c_str() == pipeline_name)
			return (*i);

	return nullptr;
}

ProgramPipeline* ProgramManager::getProgramPipeline(const GLuint pipeline_id)
{
	for (auto i = _pipelinelist.begin(); i != _pipelinelist.end(); i++)
		if ((*i)->getID() == pipeline_id)
			return (*i);

	return nullptr;
}

void ProgramManager::deleteProgram(const char* program_name)
{
	for (auto i = _programlist.begin(); i != _programlist.end(); i++)
		if ((*i)->getName().c_str() == program_name)
		{
			Program* program = (*i);

			_programlist.erase(i);
			delete program;
			//성공 로그 후 리턴
		}
	
	//실패 로그 후 리턴
}

void ProgramManager::deleteProgram(const GLuint program_id)
{
	for (auto i = _programlist.begin(); i != _programlist.end(); i++)
		if ((*i)->getID() == program_id)
		{
			Program* program = (*i);

			_programlist.erase(i);
			delete program;
			//성공 로그 후 리턴
		}

	//실패 로그 후 리턴
}


void ProgramManager::deleteAllPrograms()
{

}

void ProgramManager::deleteAllProgramPipelines()
{

}

void ProgramManager::showProgramList()
{
	//logger 작성 후 작성.
}


ProgramManager::~ProgramManager()
{
	//logger 작성 후 작성.
}


ProgramManager::ProgramManager()
{
	_programlist.clear();
	_pipelinelist.clear();
}

bool ProgramManager::init()
{
	return true;
}


