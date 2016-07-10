
#include "DrawingManager.h"
#include "Drawing.h"

#include <assert.h>

DrawingManager* DrawingManager::create()
{
	DrawingManager* drawingmanager = new DrawingManager();

	if (drawingmanager && drawingmanager->init())
	{

	}
	else
	{
		SAFE_DELETE(drawingmanager)
	}

	return drawingmanager;
}


int DrawingManager::addDrawing(Drawing* drawing)
{
	assert(drawing != nullptr);

	_drawinglist.push_back(drawing);

	int index = getDrawingIndex(drawing);

	return index;
}

Drawing* DrawingManager::getDrawingByIndex(const int drawing_index)
{
	return _drawinglist[drawing_index];
}

int DrawingManager::getDrawingIndex(Drawing* drawing)
{
	for (int i = 0; i < (int)_drawinglist.size(); i++)
		if (_drawinglist[i] == drawing)
			return i;

	const int FAILED = -1;
	return FAILED;
}

void DrawingManager::deleteDrawing(Drawing* drawing)
{
	for (auto i = _drawinglist.begin(); i != _drawinglist.end(); i++)
		if ((*i) == drawing)
		{
			Drawing* drawing = (*i);

			_drawinglist.erase(i);
			delete drawing;
		}
}

void DrawingManager::deleteAllDrawing()
{
	Drawing* drawing = nullptr;

	while (_drawinglist.empty() != true)
	{
		drawing = _drawinglist.back();

		_drawinglist.pop_back();
		delete drawing;
	}
}



DrawingManager::~DrawingManager()
{
	deleteAllDrawing();
}


DrawingManager::DrawingManager()
{
	_drawinglist.clear();
}

bool DrawingManager::init()
{
	return true;
}

