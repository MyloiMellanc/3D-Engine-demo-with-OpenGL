#ifndef __DRAWING_MANAGER__
#define __DRAWING_MANAGER__

#include "../Support/Macro.h"

#include <vector>

class Drawing;

class DrawingManager
{
public:
	static DrawingManager* create();


	//¿Œµ¶Ω∫ ∏Æ≈œ
	int addDrawing(Drawing* drawing);

	
	Drawing* getDrawingByIndex(const int drawing_index);

	int getDrawingIndex(Drawing* drawing);

	void deleteDrawing(Drawing* drawing);

	void deleteAllDrawing();

	~DrawingManager();

PROTECT_CONSTRUCTOR_ACCESS:
	DrawingManager();
	bool init();

protected:


private:
	std::vector<Drawing*> _drawinglist;


};



#endif
