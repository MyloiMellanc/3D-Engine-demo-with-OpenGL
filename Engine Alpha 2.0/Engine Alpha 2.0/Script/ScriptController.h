#ifndef __SCRIPT_CONTROLLER__
#define __SCRIPT_CONTROLLER__

#include "LuaHeader.h"

class ScriptController
{
public:

	virtual void runString(const char* string);
	virtual void runScriptFile(const char* filepath);

	virtual void addFunction(const char* func_name, ScriptFunction func);
	virtual void registerScriptFunction();


	~ScriptController();

protected:
	ScriptController();
	virtual bool init();

private:


};



#endif
