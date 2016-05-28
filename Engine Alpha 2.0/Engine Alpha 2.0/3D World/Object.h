#ifndef __OBJECT__
#define __OBJECT__

#include "../Support/cgmath.h"
#include "../Support/Demo Support.h"
#include "../Support/Macro.h"
#include <string>
#include <list>

class Action;
class World;
class Renderer;


class Object
{
public:
	
	/* This class protect constructor.
	*  This class only be created with create() method.
	*
	*/
	static Object* create();

	/*
	*	SETTER of default variable.
	*/
	void setId(int id);
	void setTag(const std::string& tag);
	void setVisible(bool visible);

	/*	Command used by external class (especially, Action).
	*	These virtual method are created not only for Object, Camera used these too.
	*	For Camera and Object(Model) can use same Action class.
	*/
	////Moving Command for override.
	////commands are divided by 'set' and 'move'
	virtual void setPosition(const vec3& position);
	virtual void MovePosition(const vec3& position);
	//virtual void setRotation(? ? ? ? );
	//virtual void moveRotation(? ? ? ? );
	virtual void setScale(const scale& volume);
	virtual void moveScale(const scale& volume);


	int getId() const;
	std::string getTag() const;
	bool isVisible() const;
	virtual vec3 getPosition() const;
	//virtual ? ? ? getRotation() const;
	virtual scale getScale() const;


	////////For Rendering.
	virtual void update(float dt);
	virtual void draw(Renderer* renderer);




	////////Manage Action
	void addAction(Action* action, bool running);
	void runAllAction();
	void stopAllAction();
	void deleteAction(Action* action);
	void deleteAllAction();


	//////setting World
	void setCurrentWorld(World* world);
	World* getCurrentWorld() const;



	~Object();

PROTECT_CONSTRUCTOR_ACCESS:
	Object();
	virtual bool init();


	////////Only used in update method.
protected:
	static void giveId(Object* object);
	void ActionUpdate(float dt);

private:
	static int OBJECT_ID;
	int _id;
	std::string _tag;
	bool _visible;

	std::list<Action*> _actionlist;

	World* _pCurrentworld;
};


#endif
