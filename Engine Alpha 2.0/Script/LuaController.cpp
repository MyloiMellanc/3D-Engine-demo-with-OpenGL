
#include "LuaController.h"
#include "LuaHeader.h"

#include "Script Function\LuaFunctionMain.h"

LuaController* LuaController::_pInstance = nullptr;

LuaController* LuaController::getInstance()
{
	if (_pInstance == nullptr)
	{
		_pInstance = new LuaController();
		if (_pInstance && _pInstance->init())
		{

		}
		else
		{
			SAFE_DELETE(_pInstance)
		}
	}

	return _pInstance;
}

void LuaController::runString(const char* string)
{
	luaL_dostring(_pLua_state, string);
}

void LuaController::runScriptFile(const char* filepath)
{
	luaL_dofile(_pLua_state, filepath);
}

void LuaController::addFunction(const char* func_name, ScriptFunction func)
{
	lua_register(_pLua_state, func_name, func);
}

void LuaController::registerScriptFunction()
{
	if (_pLua_state != nullptr)
	{
		for (int i = 0; LuaFunctions[i].name != NULL; i++)
		{
			addFunction(LuaFunctions[i].name, LuaFunctions[i].func);
		}
	}
}

LuaController::~LuaController()
{
	if (_pLua_state != nullptr)
		lua_close(_pLua_state);
}

LuaController::LuaController()
:_pLua_state(nullptr)
{

}

bool LuaController::init()
{
	_pLua_state = lua_open();
	if (_pLua_state == nullptr)
		return false;

	luaopen_base(_pLua_state);
	luaL_openlibs(_pLua_state);

	return true;
}

