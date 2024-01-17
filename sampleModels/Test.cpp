#include "pch.h"
#include "Test.h"
//#define SAMPLE_EXPORTS

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


int add_cmd(Test* inst, int a, int b) {
	int ret = inst->add(a, b);
	return ret;
}

void destroy_cmd(Test* inst) {
	inst->destroy();
}