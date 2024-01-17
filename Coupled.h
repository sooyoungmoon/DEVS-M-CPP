#pragma once
#include "Model.h"
//#include "Coup_rel.h"
#include <unordered_map>


class Coupled : public Model
{
protected:
	std::vector<Model*> components;
	std::unordered_multimap<std::string, std::string> coupling;
	//std::vector<Coup_rel*> portCoupling;
	std::list<std::string> priorLst;
	 
public:
	void insertComp(Model*);
	void removeComp(Model*);

	virtual void insertCoupling(std::string srcModel, std::string srcPort, std::string dstModel, std::string dstPort) = 0;
	virtual void removeCoupling(std::string srcModel, std::string srcPort, std::string dstModel, std::string dstPort) = 0;

	void setPriorLst(std::list<std::string> priorities);
	/*
	void insertCoupling(Coup_rel* coupling);
	void removeCouling(Coup_rel* coupling);
	
	*/
};

