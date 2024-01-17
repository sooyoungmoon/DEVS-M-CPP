#pragma once
#include "Processor.h"
class Coordinator : public Processor
{
public:
	
	void rcvStarMsg(Message& starMsg);
	void rcvXMsg(Message& xMsg);
	void rcvYMsg(Message& yMsg);		
	void rcvDoneMsg(Message& doneMsg);

protected:
	std::vector<Processor*> children; 
};

