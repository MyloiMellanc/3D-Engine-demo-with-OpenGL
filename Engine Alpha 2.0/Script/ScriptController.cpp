
#include "ScriptController.h"

void ScriptController::runString(const char* string)
{
	(void)string;
	//Override me.
}

void ScriptController::runScriptFile(const char* filepath)
{
	(void)filepath;
	//Override me.
}

void ScriptController::addFunction(const char* func_name, ScriptFunction func)
{
	(void)func_name;
	(void)func;
	//Override me.

}

void ScriptController::registerScriptFunction()
{
	//Override me.
}


ScriptController::~ScriptController()
{
	//none.
}

ScriptController::ScriptController()
{
	//none.
}

bool ScriptController::init()
{
	//Override me.
	return false;
}
