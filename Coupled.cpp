#include "Coupled.h"

using namespace std;


void Coupled::insertComp(Model* comp) {
	this->components.emplace_back(comp);
}

void Coupled::removeComp(Model* comp) {
	
	for (auto it = this->components.begin(); it != this->components.end(); it++) {
		Model* curModel = *it;

		if (curModel->getName() == comp->getName()) {
			components.erase(it);
			break;
		}
	}
}


void Coupled::setPriorLst(std::list<std::string> priorities) {
	this->priorLst = priorities;
}

