#include "Processor.h"

using namespace std;

void Processor::setName(string name) {
	this->name = name;
}

string Processor::getName() {
	return this->name;
}

void Processor::setParent(Processor* parent) {
	this->parent = parent;
}

Processor* Processor::getParent() {
	return this->parent;
}

void Processor::setTL(time_t tLastEvnt) {
	this->tL = tLastEvnt;
}

time_t Processor::getTL() {
	return this->tL;
}

void Processor::setTN(time_t tNextEvnt) {
	this->tN = tNextEvnt;
}

time_t Processor::getTN() {
	return this->tN;
}

void Processor::setModel(Model* model) {
	this->model = model;
}

Model* Processor::getModel() {
	return this->model;
}


Processor::Processor(string name, Processor* parent) {
	this->name = name;
	this->parent = parent;
}

Processor::Processor(string name) {
	this->name = name;
	this->parent = nullptr;
}