#ifndef _TEST_
#define _TEST_
#ifdef SAMPLE_EXPORTS
#define SAMPLE_API __declspec(dllexport)
#else 
#define SAMPLE_API __declspec(dllimport)
#endif

//#include "Base.h"

extern "C"  SAMPLE_API
int my_add(int a, int b);


class Test
{
public:	
	int add(int a, int b);	
	void destroy();
};


extern "C" {
	SAMPLE_API int add_cmd(Test* inst, int a, int b);
	SAMPLE_API void destroy_cmd(Test* inst);
}

#endif