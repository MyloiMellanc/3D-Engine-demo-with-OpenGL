#ifndef __DIRECTOR__
#define __DIRECTOR__

#include "../Support/Macro.h"

class Renderer;
class WorldManager;
class LayerManager;

class Director
{
public:
	static Director* getInstance();


	/////////Functions for rendering loop.
	static void Display();
	static void Reshape(int width, int height);
	static void Keyboard(unsigned char key, int x, int y);
	static void Mouse(int button, int state, int x, int y);
	static void Motion(int x, int y);
	static void Idle();

	static void Render();
	static void Update();

	////////control renderer
	void run();
	void setMainLoop();
	void end();


	~Director();


PROTECT_CONSTRUCTOR_ACCESS:
	Director();
	virtual bool init();


private:
	static Director* _pInstance;

	static Renderer* _pRenderer;
	static WorldManager* _pWorldmanager;
	static LayerManager* _pLayermanager;

};


#endif
