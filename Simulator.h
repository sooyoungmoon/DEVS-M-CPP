#pragma once
#include "Processor.h"


class Simulator : public Processor
{
private:
	
public:

	
	void rcvStarMsg(Message* starMsg);

	
	void rcvXMsg(Message* xMsg);

	
	void sndDoneMsg(time_t time);


	Simulator();
};

