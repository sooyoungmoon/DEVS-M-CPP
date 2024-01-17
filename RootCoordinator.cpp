#include "RootCoordinator.h"

RootCoordinator* RootCoordinator::uniqInst = nullptr;

int RootCoordinator::a = 0;

RootCoordinator* RootCoordinator::getInstance() { // we use the Singleton design pattern because the class may have only one instance 

	RootCoordinator::a = 3;

	if (RootCoordinator::uniqInst == nullptr) {
		uniqInst = new RootCoordinator();

	}

	return uniqInst;
}

RootCoordinator::RootCoordinator() : Processor("Root_Coord", nullptr) {


}

void RootCoordinator::rcvDoneMsg(Message& doneMsg) {
	time_t childTN = doneMsg.getMsgTime(); 

	if (childTN < this->tN) { // if the tN in the done msg is less than (earlier than) the current tN, update the tN value
		this->tN = childTN;
	}
	else {
		;
	}
}