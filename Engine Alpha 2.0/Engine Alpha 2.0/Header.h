#ifndef __HEADER__
#define __HEADER__

#define NDEBUG 1
#include <assert.h>
#include <iostream>

//////// 3D World
#include "3D World\Object.h"
#include "3D World\Action.h"
#include "3D World\Camera.h"
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
#include "Renderer\Renderer.h"
#include "Renderer\OpenGLRenderer.h"


//////// Script
#include "Script\ScriptManager.h"
#include "Script\LuaGlueManager.h"


//////// Base
#include "Base\Director.h"


//////// Support

#include "Support\cgmath.h"
#include "Support\Demo Support.h"
#include "Support\Macro.h"

#endif
