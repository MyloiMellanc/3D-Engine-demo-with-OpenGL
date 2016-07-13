#ifndef __LUA_CONTROLLER__
#define __LUA_CONTROLLER__

#include "../Support/Macro.h"

#include "ScriptController.h"

class OpenGLRenderer;

class LuaController :public ScriptController
{
public:
	static LuaController* getInstance();

	virtual void runString(const char* string);
	virtual void runScriptFile(const char* filepath);

	virtual void addFunction(const char* func_name, ScriptFunction func);
	virtual void registerScriptFunction();



	void setOpenGLRenderer(OpenGLRenderer* opengl_renderer);

	OpenGLRenderer* getOpenGLRenderer();

	~LuaController();

PROTECT_CONSTRUCTOR_ACCESS:
	LuaController();
	virtual bool init();

protected:

	OpenGLRenderer* _pOpeglrenderer;

private:
	static LuaController* _pInstance;

	lua_State* _pLua_state;
};


#endif
