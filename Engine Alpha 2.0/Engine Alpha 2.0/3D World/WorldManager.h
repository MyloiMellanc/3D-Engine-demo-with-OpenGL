#ifndef __WORLD_MANAGER__
#define __WORLD_MANAGER__

#include "../Support/Macro.h"
#include <vector>

class World;
class Renderer;
class Director;

class WorldManager
{
public:
	static WorldManager* create();

	////////manage world - called by Director
	void addWorld(World* world);

	int findWorldIndex(World* world);
	int findWorldIndexById(int id);

	void setCurrentWorld(World* world);
	void setCurrentWorldById(int id);

	World* getWorld(const int id);

	World* getCurrentWorld() const;


	////////change currentworld to nullworld
	void clearCurrentWorld();

	void deleteWorld(World* world);
	void deleteWorldById(int id);

	////////command methods
	void update(float dt);
	void draw(Renderer* renderer);


	~WorldManager();
	
PROTECT_CONSTRUCTOR_ACCESS:
	WorldManager();
	bool init();


private:
	std::vector<World*> _Worldlist;
	World* _pCurrentworld;
	World* _pNullworld;

};

#endif
