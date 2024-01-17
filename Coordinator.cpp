#include "Coordinator.h"


void Coordinator::rcvStarMsg(Message& starMsg) {

	// 1. compare its tN value with the time in the starMsg
	if (starMsg.getMsgTime() != this->tN) { // 1-1 If they do not match, return to the caller
		return;
	}
	else { // 1-2. If they match, proceed to the next step.

		for (auto it = this->children.begin(); it != this->children.end(); it++) { // �ڽ� ���μ����� �� ���� �̺�Ʈ �߻� �ð��� ���� coordinator�� tN���� ��ġ�ϴ� ���� ����, �ش� �ڽ� ���μ����� star message ���� 
			Processor* child = *it; 

			time_t childTN = child->getTN();

			if (this->tN == childTN) {
				child->rcvStarMsg(starMsg);
				break;
			}
		}

	}
	

}

void Coordinator::rcvXMsg(Message& xMsg) {


}

void Coordinator::rcvYMsg(Message& yMsg) {

}

void Coordinator::rcvDoneMsg(Message& doneMsg) {
	// 1. �ڽ��� tN ���� doneMsg �� time �� ��
	time_t childTN = doneMsg.getMsgTime();
	
	if (childTN < this->tN) { // �ڽ� ���μ����� tN�� ���� ���μ������� �� ���� ���, tN �� ������Ʈ �� done msg ����, �θ� ���μ������� ����
		this->tN = childTN;

		if (this->parent != NULL) {
			this->parent->rcvDoneMsg(doneMsg);
		}
	}
	else {
		return; //
	}

}