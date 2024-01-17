#include "pch.h"
#include "Test.h"
#define SAMPLE_EXPORTS

int Test::add(int a, int b) {
	return a + b;
}

void Test::destroy() {
	delete this;
}


int my_add(int a, int b)
{
	return a + b;
}
