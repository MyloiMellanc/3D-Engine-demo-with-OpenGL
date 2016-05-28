#ifndef __MACRO__
#define __MACRO__

#define PROTECT_CONSTRUCTOR_ACCESS protected

#define SAFE_DELETE(instance) do {if(instance) {delete(instance); instance = 0;}} while(nullptr);


#endif
