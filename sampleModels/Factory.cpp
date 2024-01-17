#include "pch.h"
#include "Factory.h"

//#define SAMPLE_EXPORTS

Test* createTest() // a function to create and return the Test instance
{
	return new Test();
}


