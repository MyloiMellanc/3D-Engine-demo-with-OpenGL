#ifndef __RENDERER__
#define __RENDERER__

#include "../Support/cgmath.h"
#include "../Support/Macro.h"

enum MATRIX_TYPE {
	MODEL,
	VIEW,
	PROJECTION
};

enum MODEL {
	DRAGON
};

class Renderer
{
public:
	static Renderer* create(int argc, char* argv[]);

	////////method for other classes
	virtual void pushMatrix(int matrix_type, const mat4& matrix);
	virtual void drawModel(int model_id);

	virtual void setMainLoop();
	
	
	~Renderer();

PROTECT_CONSTRUCTOR_ACCESS:
	Renderer();
	virtual bool init(int argc, char* argv[]);

};


#endif
