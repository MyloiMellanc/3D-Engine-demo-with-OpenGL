#ifndef __MACRO__
#define __MACRO__

#define PROTECT_CONSTRUCTOR_ACCESS protected

//#define SAFE_DELETE(instance) do {if(instance) {delete(instance); instance = nullptr;}} while(0);
#define SAFE_DELETE(instance) do {delete(instance); instance = nullptr;} while(0);

#endif
