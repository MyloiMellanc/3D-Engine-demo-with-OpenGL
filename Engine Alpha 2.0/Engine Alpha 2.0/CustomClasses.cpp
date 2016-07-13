
#include "CustomClasses.h"



void Cube::update(float dt)
{

}

void Cube::draw(Renderer* renderer)
{
	renderer->setDrawing(getDrawingID());

	mat4 model = mat4::translate(_position);
	

	renderer->pushMatrix(MATRIX_TYPE::MODEL, model);

	renderer->draw();
}

Cube::Cube()
{
	init();
}

bool Cube::init()
{
	_position = vec3(0, 0, 0);
	return true;
}


void CubeDrawing::draw()
{
	bindVAO();

	_index->Bind();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, NULL);
}