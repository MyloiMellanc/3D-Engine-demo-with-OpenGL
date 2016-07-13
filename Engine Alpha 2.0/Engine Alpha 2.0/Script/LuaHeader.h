#ifndef __LUA_HEADER__
#define __LUA_HEADER__



#include <stdio.h>
#include <string.h>
#include <string>

extern "C"
{
#include "Lua Library\include\lua.h"
#include "Lua Library\include\lualib.h"
#include "Lua Library\include\lauxlib.h"
}

#pragma comment (lib, "lua51.lib")
#pragma comment (lib, "lua5.1.lib")

#define LUAGLUE extern "C" int

extern "C"
{
	typedef int(*ScriptFunction)(lua_State* L);
}


#endif
