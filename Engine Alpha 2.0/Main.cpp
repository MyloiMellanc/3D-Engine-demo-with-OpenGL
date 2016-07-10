#include "Header.h"


void main(int argc, char* argv[])
{
	WorldManager* worldmanager = WorldManager::create();

	OpenGLRenderer* openglrenderer = OpenGLRenderer::create(argc, argv, "demo");
	openglrenderer->setMainLoop();

	Director::getInstance()->setWorldManager(worldmanager);
	Director::getInstance()->setRenderer(openglrenderer);

	Director::getInstance()->run();


}