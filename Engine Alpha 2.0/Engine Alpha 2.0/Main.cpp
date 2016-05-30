#include "Header.h"


void printobj(Object* obj)
{
	std::cout << "Object ID : " << obj->getId() << std::endl;
	std::cout << "Object Tag : " << obj->getTag() << std::endl;
}

void printcam(Camera* cam)
{
	vec3 pos = cam->getPosition();
	vec3 lookat = cam->getLookAt();
	vec3 up = cam->getUp();
	std::cout << "cam pos : " << pos.x << pos.y << pos.z << std::endl;
	std::cout << "cam lookat : " << lookat.x << lookat.y << lookat.z << std::endl;
	std::cout << "cam up : " << up.x << up.y << up.z << std::endl;
}


void main(int argc, char* argv[])
{
	Object* obj1 = Object::create();
	Object* obj2 = Object::create();
	Action* act1 = Action::create();
	Camera* cam1 = Camera::create();

	printobj(obj1);
	printobj(obj2);
	printcam(cam1);


	World* wor1 = World::create();
	WorldManager* wma1 = WorldManager::create();

	Director::getInstance();

	obj1->addAction(act1, false);
	wor1->addObject(obj1);
	wor1->addObjectWithTag(obj2, "obj2");

	wor1->setCamera(cam1);
	wma1->addWorld(wor1);
	
	wma1->setCurrentWorldById(1);

	Director::getInstance()->setWorldManager(wma1);

	


}