
#include "Logger.h"
#include "../Support/Macro.h"

#include <iostream>
#include <stdarg.h>


Logger* Logger::_pInstance = nullptr;


Logger* Logger::getInstance()
{
	if (_pInstance == nullptr)
	{
		_pInstance = new Logger();
		if (_pInstance && _pInstance->init())
		{

		}
		else
		{
			SAFE_DELETE(_pInstance)
		}
	}

	return _pInstance;
}

void Logger::pushLog(char* format, ...)
{
	va_list arg;
	char c;
	char* s;
	int d;
	float f;


	va_start(arg, format);

	for (int i = 0; format[i] != NULL; i++)
	{
		if (format[i] == '%')
		{
			i++;

			switch (format[i])
			{
			case 'c' :
				c = (char)va_arg(arg, char);
				std::cout << c;
				break;
			case 's' :
				s = (char*)va_arg(arg, char*);
				std::cout << s;
				break;
			case 'd':
				d = (int)va_arg(arg, int);
				std::cout << d;
				break;
			case 'f':
				f = (float)va_arg(arg, float);
				std::cout << f;
				break;


			}
		}
		else
		{
			std::cout << format[i];
		}
	}

	va_end(arg);

	return;
}


Logger::~Logger()
{
	//none
}


Logger::Logger()
{
	//none
	//_pInstance is initialized by up to 
}

bool Logger::init()
{
	return true;
}

