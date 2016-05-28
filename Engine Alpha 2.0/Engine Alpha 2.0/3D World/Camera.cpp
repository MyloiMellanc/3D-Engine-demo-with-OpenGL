#include "Camera.h"
#include "World.h"
#include "../Support/Macro.h"
#include "../Support/cgmath.h"


Camera* Camera::create()
{
	Camera* camera = new Camera();
	if (camera && camera->init())
	{

	}
	else
	{
		SAFE_DELETE(camera)
	}

	return camera;
}


void Camera::setPosition(const vec3& position)
{
	_position = position;

	toggleViewMatrix();
}

void Camera::MovePosition(const vec3& position)
{
	_position += position;

	toggleViewMatrix();
}

//void Camera::setRotation(? ? ? ? )
//void Camera::moveRotation(? ? ? ? )

void Camera::setScale(const scale& volume)
{
	//It does nothing (Camera doesn't have scale).
}

void Camera::moveScale(const scale* volume)
{
	//It does nothing (Camera doesn't have scale).
}


vec3 Camera::getPosition() const
{
	return _position;
}

//??? Camera::getRitation() const

scale Camera::getScale() const
{
	//It does nothing (Camera doesn't have scale).
}


void Camera::update(float dt)
{
	ActionUpdate(dt);
}

void Camera::draw(Renderer* renderer)
{
	//code this when Renderer is finished.
}

void Camera::pushMatrix(Renderer* renderer)
{
	//code this when Renderer is finished.
}


void Camera::setLookAt(const vec3& lookat)
{
	_lookat = lookat;

	toggleViewMatrix();
}

void Camera::setUp(const vec3& up)
{
	_up = up;

	toggleViewMatrix();
}

void Camera::updateViewMatrix()
{
	_viewmatrix = mat4::lookAt(_position, _lookat, _up);

	untoggleViewMatrix();
}

void Camera::setFovy(float fovy)
{
	_fovy = fovy;

	toggleProjectionMatrix();
}

void Camera::setAspectRatio(float aspectratio)
{
	_aspectratio = aspectratio;

	toggleProjectionMatrix();
}

void Camera::setDNear(float dnear)
{
	_dnear = dnear;

	toggleProjectionMatrix();
}

void Camera::setDFar(float dfar)
{
	_dfar = dfar;

	toggleProjectionMatrix();
}

void Camera::updateProjectionMatrix()
{
	_projectionmatrix = mat4::perspective(_fovy, _aspectratio, _dnear, _dfar);

	untoggleProjectionMatrix();
}


void Camera::toggleViewMatrix()
{
	_viewtoggle = true;
}

void Camera::toggleProjectionMatrix()
{
	_projectiontoggle = true;
}

void Camera::untoggleViewMatrix()
{
	_viewtoggle = false;
}

void Camera::untoggleProjectionMatrix()
{
	_projectiontoggle = false;
}


vec3 Camera::getPosition() const
{
	return _position;
}

vec3 Camera::getLookAt() const
{
	return _lookat;
}

vec3 Camera::getUp() const
{
	return _up;
}

mat4 Camera::getViewMatrix() const
{
	return _viewmatrix;
}

float Camera::getFovy() const
{
	return _fovy;
}

float Camera::getAspectRatio() const
{
	return _aspectratio;
}

float Camera::getDNear() const
{
	return _dnear;
}

float Camera::getDFar() const
{
	return _dfar;
}

mat4 Camera::getProjectionMatrix() const
{
	return _projectionmatrix;
}


Camera::~Camera()
{
	_pCurrentworld->setCamera(nullptr);
}


Camera::Camera()
: _position(vec3())
, _lookat(vec3())
, _up(vec3())
, _viewtoggle(false)
, _viewmatrix(mat4())
, _fovy(PI/6.0f)
, _aspectratio(1.0f)
, _dnear(1.0f)
, _dfar(1000.0f)
, _pCurrentworld(nullptr)
{

}

bool Camera::init()
{
	return true;
}

