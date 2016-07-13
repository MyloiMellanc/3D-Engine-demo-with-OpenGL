#ifndef __LUA_FUNCTION_DEMO__
#define __LUA_FUNCTION_DEMO__


#include "../LuaHeader.h"

LUAGLUE _createShader(lua_State* L);
LUAGLUE _createProgram(lua_State* L);
LUAGLUE _addShaderToProgram(lua_State* L);
LUAGLUE _linkProgram(lua_State* L);
LUAGLUE _createProgramPipeline(lua_State* L);
LUAGLUE _setShadersetToPipeline(lua_State* L);
LUAGLUE _createBuffer(lua_State* L);

LUAGLUE _setProgramToDrawing(lua_State* L);
LUAGLUE _setPipelineToDrawing(lua_State* L);
LUAGLUE _matchBufferToDrawing(lua_State* L);
LUAGLUE _createWorld(lua_State* L);
LUAGLUE _setCurrentWorld(lua_State* L);
LUAGLUE _createCameraToWorld(lua_State* L);

LUAGLUE _setDemoGraphicInterface(lua_State* L);
LUAGLUE _setDemoWorldInterface(lua_State* L);
LUAGLUE _createCubeDrawing(lua_State* L);



static luaL_reg LuaFunctions[] = 
{
	{"createShader", _createShader},
	{"createProgram", _createProgram},
	{"addShaderToProgram", _addShaderToProgram},
	{"linkProgram", _linkProgram},
	{"createProgramPipeline", _createProgramPipeline},
	{"setShadersetToPipeline", _setShadersetToPipeline},
	{"createBuffer", _createBuffer},
	{"setProgramToDrawing", _setProgramToDrawing},
	{"setPipelineToDrawing", _setPipelineToDrawing},
	{"matchBufferToDrawing", _matchBufferToDrawing},
	{"createWorld", _createWorld},
	{"setCurrentWorld", _setCurrentWorld},
	{"createCameraToWorld", _createCameraToWorld},

	{"setDemoGraphicInterface", _setDemoGraphicInterface},
	{"setDemoWorldInterface", _setDemoWorldInterface},

	{ "createCubeDrawing", _createCubeDrawing },

	{NULL,NULL}
};



#endif
