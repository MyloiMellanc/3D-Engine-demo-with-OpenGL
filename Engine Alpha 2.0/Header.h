#ifndef __HEADER__
#define __HEADER__

#define NDEBUG 1
#include <assert.h>
#include <iostream>


//////// Support

#include "Support\cgmath.h"
#include "Support\Demo Support.h"
#include "Support\Macro.h"

//Support - Logger
#include "Support\Logger.h"


//////// 3D World
#include "3D World\Object.h"
#include "3D World\Action.h"
#include "3D World\Camera.h"
#include "3D World\NullCamera.h"
#include "3D World\World.h"
#include "3D World\NullWorld.h"
#include "3D World\WorldManager.h"


//////// 2D Layer
#include "2D Layer\Node.h"
#include "2D Layer\Sprite.h"
#include "2D Layer\Layer.h"
#include "2D Layer\NullLayer.h"
#include "2D Layer\LayerManager.h"


//////// Renderer
#include "Renderer\GLSupport.h"

#include "Renderer\Renderer.h"
#include "Renderer\OpenGLRenderer.h"
#include "Renderer\Shader.h"
#include "Renderer\ShaderManager.h"
#include "Renderer\RenderObject.h"
#include "Renderer\Program.h"
#include "Renderer\ProgramPipeline.h"
#include "Renderer\ShaderManager.h"
#include "Renderer\ProgramManager.h"
#include "Renderer\Buffer.h"
#include "Renderer\BufferData.h"
#include "Renderer\BufferManager.h"
#include "Renderer\VertexArayObject.h"
#include "Renderer\Drawing.h"


//////// Script
#include "Script\LuaHeader.h"

#include "Script\ScriptController.h"
#include "Script\LuaController.h"


//////// Base
#include "Base\Director.h"



#endif
