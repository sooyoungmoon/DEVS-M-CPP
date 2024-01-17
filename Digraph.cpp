#include "Digraph.h"

using namespace std;

void Digraph::insertCoupling(std::string srcModel, std::string srcPort, std::string dstModel, std::string dstPort) { // ex. "Bank.in", "Queue.in"

	string srcMPStr = srcModel.append(".").append(srcPort);
	string dstMPStr = dstModel.append(".").append(dstPort);

	this->coupling.emplace(srcMPStr, dstMPStr);
}


void Digraph::removeCoupling(std::string srcModel, std::string srcPort, std::string dstModel, std::string dstPort) {

	string srcMPStr = srcModel.append(".").append(srcPort);
	string dstMPStr = dstModel.append(".").append(dstPort);

	unordered_map<string, string>::iterator it;

	for (it = coupling.begin(); it != coupling.end(); it++) { // src model/port�� dst model/port�� ��� ��ġ�ϸ� coupling ��Ͽ��� ���� 
		if (it->first == srcMPStr && it->second == dstMPStr) {
			coupling.erase(it);
			break;
		}
	}

}
