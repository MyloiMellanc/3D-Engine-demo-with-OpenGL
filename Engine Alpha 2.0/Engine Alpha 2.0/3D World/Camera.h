#ifndef __CAMERA__
#define __CAMERA__

#include "Object.h"
#include "../Support/cgmath.h"
#include "../Support/Demo Support.h"
#include "../Support/Macro.h"

class Renderer;
class World;

class Camera : public Object
{
public:
	static Camera* create();

	////////command from object
	virtual void setPosition(const vec3& position);
	virtual void MovePosition(const vec3& position);
	//virtual void setRotation(? ? ? ? );
	//virtual void moveRotation(? ? ? ? );
	virtual void setScale(const scale& volume);
	virtual void moveScale(const scale* volume);

	virtual vec3 getPosition() const;
	//virtual ??? getRitation() const;
	virtual scale getScale() const;

	////////command methods
	virtual void update(float dt);
	virtual void draw(Renderer* renderer);

	////////send matrix to renderer
	void pushMatrix(Renderer* renderer);

	////////manage additional variable of camera
	void setLookAt(const vec3& lookat);
	void setUp(const vec3& up);

	void updateViewMatrix();

	void setFovy(float fovy);
	void setAspectRatio(float aspectratio);
	void setDNear(float dnear);
	void setDFar(float dfar);

	void updateProjectionMatrix();

	void toggleViewMatrix();
	void toggleProjectionMatrix();
	void untoggleViewMatrix();
	void untoggleProjectionMatrix();

	////////GETTER
	
	vec3 getPosition() const;
	vec3 getLookAt() const;
	vec3 getUp() const;

	mat4 getViewMatrix() const;

	float getFovy() const;
	float getAspectRatio() const;
	float getDNear() const;
	float getDFar() const;

	mat4 getProjectionMatrix() const;


	~Camera();
	

PROTECT_CONSTRUCTOR_ACCESS:
	Camera();
	virtual bool init();


private:
	vec3 _position;
	vec3 _lookat;
	vec3 _up;

	bool _viewtoggle;
	mat4 _viewmatrix;


	float _fovy;
	float _aspectratio;
	float _dnear;
	float _dfar;

	bool _projectiontoggle;
	mat4 _projectionmatrix;


	World* _pCurrentworld;

};

#endif
