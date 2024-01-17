#include "Port.h"

using namespace std;

string Port::getName() {
	return this->name;
}

void Port::setName(string pName) {
	this->name = pName;
}

string Port::getType() {
	return this->type;
}

void Port::setType(string pType) {
	this->type = pType;
}

Model* Port::getModel() {
	return this->model;
}

void Port::setModel(Model* aModel) {
	this->model = aModel;
}
