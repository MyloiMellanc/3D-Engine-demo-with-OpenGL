
#include "LuaFunctionMain.h"

#include "../../CustomClasses.h"


LUAGLUE _createShader(lua_State* L)
{
	const char* shader_name = luaL_optstring(L, 1, NULL); 
	int shader_type = luaL_optinteger(L, 2, -1);
	const char* filepath = luaL_optstring(L, 3, NULL); 
	
	GLenum real_shader_type;
	switch (shader_type)
	{
	case SHADER_TYPE::VERTEX :
		real_shader_type = GL_VERTEX_SHADER;
		break;
	case SHADER_TYPE::FRAGMENT :
		real_shader_type = GL_FRAGMENT_SHADER;
		break;
	}
	Shader* shader = Shader::create(shader_name, real_shader_type, filepath);

	OpenGLRenderer* renderer = LuaController::getInstance()->getOpenGLRenderer();
	renderer->getShaderManager()->addShader(shader);

	lua_pushinteger(L, shader->getID());

	return 1;
}

LUAGLUE _createProgram(lua_State* L)
{
	const char* program_name = luaL_optstring(L, 1, NULL);

	Program* program = Program::create(program_name);

	OpenGLRenderer* renderer = LuaController::getInstance()->getOpenGLRenderer();
	renderer->getProgramManager()->addProgram(program);

	lua_pushinteger(L, program->getID());

	return 1;

}

LUAGLUE _addShaderToProgram(lua_State* L)
{
	GLuint program_id = (unsigned int)luaL_optinteger(L, 1, -1);
	GLenum shader_type = (unsigned int)luaL_optinteger(L, 2, -1);
	GLuint shader_id = (unsigned int)luaL_optinteger(L, 3, -1);

	OpenGLRenderer* renderer = LuaController::getInstance()->getOpenGLRenderer();
	Program* program = renderer->getProgramManager()->getProgram(program_id);
	Shader* shader = renderer->getShaderManager()->getShader(shader_id);

	program->addShader(shader_type, shader);

	return 0;
}

LUAGLUE _linkProgram(lua_State* L)
{
	GLuint program_id = (unsigned int)luaL_optinteger(L, 1, -1);
	int separable = luaL_optinteger(L, 2, 0);

	OpenGLRenderer* renderer = LuaController::getInstance()->getOpenGLRenderer();
	Program* program = renderer->getProgramManager()->getProgram(program_id);
	program->Link((bool)separable);

	return 0;
}

LUAGLUE _createProgramPipeline(lua_State* L)
{
	const char* pipeline_name = luaL_optstring(L, 1, NULL);
	ProgramPipeline* pipeline = ProgramPipeline::create(pipeline_name);

	
	OpenGLRenderer* renderer = LuaController::getInstance()->getOpenGLRenderer();
	renderer->getProgramManager()->addProgramPipeline(pipeline);

	lua_pushinteger(L, pipeline->getID());

	return 1;
}

LUAGLUE _setShadersetToPipeline(lua_State* L)
{
	GLuint pipeline_id = (unsigned int)luaL_optinteger(L, 1, -1);

	GLuint vertex_id = (unsigned int)luaL_optinteger(L, 2, -1);
	GLuint tess_control_id = (unsigned int)luaL_optinteger(L, 3, -1);
	GLuint tess_eval_id = (unsigned int)luaL_optinteger(L, 4, -1);
	GLuint geometry_id = (unsigned int)luaL_optinteger(L, 5, -1);
	GLuint compute_id = (unsigned int)luaL_optinteger(L, 6, -1);
	GLuint fragment_id = (unsigned int)luaL_optinteger(L, 7, -1);

	shader_set shaderset = { vertex_id, tess_control_id, tess_eval_id, geometry_id, compute_id, fragment_id };
	
	OpenGLRenderer* renderer = LuaController::getInstance()->getOpenGLRenderer();
	ProgramPipeline* pipeline = renderer->getProgramManager()->getProgramPipeline(pipeline_id);

	pipeline->setShaderSet(shaderset);

	return 0;

}

LUAGLUE _createBuffer(lua_State* L)
{
	//º¸·ù.
	return 0;
}


LUAGLUE _setProgramToDrawing(lua_State* L)
{
	int drawing_index = luaL_optinteger(L, 1, -1);
	GLuint program_id = (unsigned int)luaL_optinteger(L, 2, -1);

	OpenGLRenderer* renderer = LuaController::getInstance()->getOpenGLRenderer();
	Drawing* drawing = renderer->getDrawingManager()->getDrawingByIndex(drawing_index);
	Program* program = renderer->getProgramManager()->getProgram(program_id);

	drawing->setRenderObject(program);
	drawing->updateRenderObjectInfo();
	return 0;
}

LUAGLUE _setPipelineToDrawing(lua_State* L)
{
	int drawing_index = luaL_optinteger(L, 1, -1);
	GLuint pipeline_id = (unsigned int)luaL_optinteger(L, 2, -1);

	OpenGLRenderer* renderer = LuaController::getInstance()->getOpenGLRenderer();
	Drawing* drawing = renderer->getDrawingManager()->getDrawingByIndex(drawing_index);
	ProgramPipeline* pipeline = renderer->getProgramManager()->getProgramPipeline(pipeline_id);

	drawing->setRenderObject(pipeline);
	drawing->updateRenderObjectInfo();

	return 0;
}

LUAGLUE _matchBufferToDrawing(lua_State* L)
{
	if (lua_gettop(L) < 2)
		return 0;

	OpenGLRenderer* renderer = LuaController::getInstance()->getOpenGLRenderer();

	GLuint drawing_index = (unsigned int)luaL_optinteger(L, 1, -1);
	Drawing* drawing = renderer->getDrawingManager()->getDrawingByIndex(drawing_index);

	std::vector<Buffer*> buffer_list;
	GLuint buffer_id;
	
	BufferManager* buf_manager = renderer->getBufferManager();
	Buffer* buffer;

	int max = lua_gettop(L) + 1;

	for (int i = 2; i < max; i++)
	{
		buffer_id = (unsigned int)luaL_optinteger(L, i, -1);

		buffer = buf_manager->getBuffer(buffer_id);
		buffer_list.push_back(buffer);
	}


	for (unsigned int i = 0; i < buffer_list.size(); i++)
	{
		drawing->linkBufferToAttribute(buffer_list.at(i));
	}
	
	drawing->updateVAO();

	return 0;
}

LUAGLUE _createWorld(lua_State* L)
{
	const char* world_name = luaL_optstring(L, 1, NULL);

	World* world = World::create();
	world->setName(world_name);

	Director::getInstance()->getWorldManager()->addWorld(world);

	lua_pushinteger(L, world->getId());

	return 1;
}

LUAGLUE _setCurrentWorld(lua_State* L)
{
	int world_id = luaL_optinteger(L, 1, -1);

	Director::getInstance()->getWorldManager()->setCurrentWorldById(world_id);


	return 0;
}

LUAGLUE _createCameraToWorld(lua_State* L)
{
	int world_id = luaL_optinteger(L, 1, -1);

	const char* cam_list[] = { "position", "up", "lookat" };
	float value[10];

	for (int i = 0; i < 3; i++)
	{
		lua_pushstring(L, cam_list[i]);
		lua_gettable(L, 2);
	
		for (int j = 1; j < 4; j++)
		{
			lua_pushinteger(L, j);
			lua_gettable(L, 3);

			value[3 * i + j] = (float)luaL_optnumber(L, 4, 9999);
			lua_pop(L, 1);
		}

		lua_pop(L, 1);
	}

	Camera* camera = Camera::create();
	camera->setPosition(vec3(value[1], value[2], value[3]));
	camera->setUp(vec3(value[4], value[5], value[6]));
	camera->setLookAt(vec3(value[7], value[8], value[9]));


	Director::getInstance()->getWorldManager()->getWorld(world_id)->setCamera(camera);

	return 0;
}


LUAGLUE _setDemoGraphicInterface(lua_State* L)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);		// clear color for glClear()
	glEnable(GL_CULL_FACE);					// turn on backface culling
	glEnable(GL_DEPTH_TEST);					// turn on depth tests
										
	
	const float d = 0.5f;
	vec3 vertices[8];
	vertices[0] = vec3(-d, -d, +d);
	vertices[1] = vec3(+d, -d, +d);
	vertices[2] = vec3(+d, -d, -d);
	vertices[3] = vec3(-d, -d, -d);
	vertices[4] = vec3(-d, +d, +d);
	vertices[5] = vec3(+d, +d, +d);
	vertices[6] = vec3(+d, +d, -d);
	vertices[7] = vec3(-d, +d, -d);


	Buffer* cube_buffer = Buffer::create("cube_vertex", GL_ARRAY_BUFFER, GL_FLOAT_VEC3);
	cube_buffer->Bind();
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	// IBA = index buffer array
	GLuint IBA[36] =
	{
		0, 1, 4,        // front
		1, 5, 4,        // front
		1, 2, 5,        // right
		2, 6, 5,        // right
		0, 4, 3,        // left
		4, 7, 3,        // left
		7, 6, 2,        // back
		3, 7, 2,        // back
		7, 4, 5,        // top
		6, 7, 5,        // top
		0, 3, 1,        // bottom
		1, 3, 2,        // bottom
	};

	Buffer* cube_index = Buffer::create("cube_index", GL_ELEMENT_ARRAY_BUFFER, GL_UNSIGNED_INT);
	cube_index->Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(IBA), IBA, GL_STATIC_DRAW);


	BufferManager* buf_manager = LuaController::getInstance()->getOpenGLRenderer()->getBufferManager();

	buf_manager->addBuffer(cube_buffer);
	buf_manager->addBuffer(cube_index);

	lua_pushinteger(L, cube_buffer->getID());
	lua_pushinteger(L, cube_index->getID());
	
	return 2;
}

LUAGLUE _setDemoWorldInterface(lua_State* L)
{
	Cube* cube = new Cube();
	
	int drawing_id = luaL_optinteger(L, 1, -1);

	cube->setDrawingID(drawing_id);
	
	Director::getInstance()->getWorldManager()->getCurrentWorld()->addObject(cube);
	
	return 0;
}



LUAGLUE _createCubeDrawing(lua_State* L)
{
	const char* drawing_name = luaL_optstring(L, 1, NULL);

	GLuint cube_index_id = (unsigned int)luaL_optinteger(L, 2, -1);
	OpenGLRenderer* renderer = LuaController::getInstance()->getOpenGLRenderer();
	Buffer* cube_index_buffer = renderer->getBufferManager()->getBuffer(cube_index_id);

	CubeDrawing* drawing = new CubeDrawing();
	drawing->initVertexArrayObject();
	drawing->setName(drawing_name);
	drawing->_index = cube_index_buffer;



	int drawing_index = renderer->getDrawingManager()->addDrawing(drawing);

	lua_pushinteger(L, drawing_index);

	return 1;
}