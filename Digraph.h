#pragma once
#include "Coupled.h"
class Digraph : public Coupled
{
public:
	void insertCoupling(std::string srcModel, std::string srcPort, std::string dstModel, std::string dstPort);
	void removeCoupling(std::string srcModel, std::string srcPort, std::string dstModel, std::string dstPort);
};

