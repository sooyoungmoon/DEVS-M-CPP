#include "Model.h"
#include <climits>
using namespace std;

string Model::getName() {
	return this->name;
}

Model* Model::getParent() {
	return this->parent;
}

void Model::setProc(Processor* processor) {
	this->processor = processor;
}

Processor* Model::getProc() {
	return this->processor;
}

Model::Model(string name, Model* parent) {
	this->name = name;
	this->parent = parent;
	this->sigma = LLONG_MAX;
	this->phase = "";
}

Model::Model() {
	Model("", nullptr);
}


















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































