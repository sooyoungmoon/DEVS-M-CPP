// 22.01.22
// Moontail
// Processor class in my DEVS simulation framework

#pragma once
#include "Model.h"
#include "Message.h"
#include <ctime>
#include <vector>
#include <string>
#include <cassert>

class Model;
class Message;


class Processor
{
protected:
	std::string name;
	Processor* parent;
	Model* model;
	time_t tL;
	time_t tN;

public:

	void setName(std::string name);
	std::string getName();

	void setParent(Processor* parent);
	Processor* getParent();
	   

	void setTL(time_t tLastEvnt);
	time_t getTL();

	void setTN(time_t tNextEvnt);
	time_t getTN();

	void setModel(Model* model);
	Model* getModel();

	
	virtual void rcvStarMsg(Message& starMsg) = 0 ;	
	virtual void sndStarMsg(Message& starMsg) = 0;	
	virtual void rcvXMsg(Message& xMsg) = 0;	
	virtual void sndXMsg(Message& xMsg) = 0;	
	virtual void rcvYMsg(Message& yMsg) = 0;	
	virtual void sndYMsg(Message& yMsg) = 0;
	virtual void rcvDoneMsg(Message& doneMsg) = 0;
	virtual void sndDoneMsg(Message& doneMsg) = 0;

	Processor(std::string name, Processor* parent);
	Processor(std::string name);
};

