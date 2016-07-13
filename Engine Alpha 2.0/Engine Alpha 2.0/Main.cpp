
#include "CustomClasses.h"

void main(int argc, char* argv[])
{
	WorldManager* worldmanager = WorldManager::create();

	OpenGLRenderer* openglrenderer = OpenGLRenderer::create(argc, argv, "demo");
	openglrenderer->setMainLoop();

	Director::getInstance()->setWorldManager(worldmanager);
	Director::getInstance()->setRenderer(openglrenderer);

	LuaController::getInstance()->runScriptFile("begin.lua");


	Director::getInstance()->run();


}