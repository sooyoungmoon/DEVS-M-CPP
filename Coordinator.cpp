#include "Coordinator.h"


void Coordinator::rcvStarMsg(Message& starMsg) {

	// 1. compare its tN value with the time in the starMsg
	if (starMsg.getMsgTime() != this->tN) { // 1-1 If they do not match, return to the caller
		return;
	}
	else { // 1-2. If they match, proceed to the next step.

		for (auto it = this->children.begin(); it != this->children.end(); it++) { // 자식 프로세서들 중 다음 이벤트 발생 시각이 현재 coordinator의 tN값과 일치하는 것을 선택, 해당 자식 프로세서에 star message 전달 
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
	// 1. 자신의 tN 값과 doneMsg 내 time 값 비교
	time_t childTN = doneMsg.getMsgTime();
	
	if (childTN < this->tN) { // 자식 프로세서의 tN이 현재 프로세서보다 더 작은 경우, tN 값 업데이트 후 done msg 생성, 부모 프로세서에게 전달
		this->tN = childTN;

		if (this->parent != NULL) {
			this->parent->rcvDoneMsg(doneMsg);
		}
	}
	else {
		return; //
	}

}