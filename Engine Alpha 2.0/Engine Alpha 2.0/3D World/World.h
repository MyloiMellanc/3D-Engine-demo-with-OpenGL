#ifndef __WORLD__
#define __WORLD__

#include "../Support/Macro.h"
#include <string>
#include <vector>

class Object;
class Camera;
class Renderer;

class World
{
public:
	static World* create();

	////////ID manage.
	void setId(int id);
	int getId() const;

	////////Add Object in list
	void addObject(Object* object);
	void addObjectWithTag(Object* object, const std::string& tag);

	////////find object
	Object* getObjectById(int id);

	////////number of object
	int getObjectCount() const;
	int getObjectCountByTag(const std::string& tag) const;

	////////remove object
	void deleteObject(Object* object);
	void deleteObjectById(int id);
	void deleteObjectByTag(const std::string& tag);
	void deleteAllObject();

	////////control visibility? of object
	void seeAllObject();
	void closeAllObject();
	void seeObjectById(int id);
	void closeObjectById(int id);
	void seeAllObjectByTag(const std::string& tag);
	void closeAllObjectByTag(const std::string& tag);

	////////manage camera
	void setCamera(Camera* camera);
	Camera* getCamera() const;


	////////command methods
	virtual void update(float dt);
	virtual void draw(Renderer* renderer);


	~World();

PROTECT_CONSTRUCTOR_ACCESS:
	World();
	bool init();

protected:
	static void giveId(World* world);
		
private:
	static int WORLD_ID;
	int _id;

	Camera* _pCurrentcamera;

	std::vector<Object*> _objectlist;
};

#endif
