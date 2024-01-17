
#ifdef SAMPLE_EXPORTS
#define SAMPLE_API __declspec(dllexport)
#else 
#define SAMPLE_API __declspec(dllimport)
#endif

//#include "Base.h"

extern "C"  SAMPLE_API
int my_add(int a, int b);


class SAMPLE_API Test
{
public:
	
	int add(int a, int b);	
	void destroy();
};


