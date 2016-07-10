#ifndef __LOGGER__
#define __LOGGER__


#include "Macro.h"

class Logger
{
public:
	static Logger* getInstance();

	void pushLog(char* format, ...);
	

	~Logger();

PROTECT_CONSTRUCTOR_ACCESS:
	Logger();
	bool init();

protected:



private:
	static Logger* _pInstance;

};



#endif
