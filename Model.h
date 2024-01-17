#pragma once
#include "Processor.h"
#include "Port.h"
#include "typedef.h"
#include "Message.h"
#include "Content.h"
#include <string>
#include <vector>


class Processor;
class Message;
class Content;
class Port;
class Model
{
protected:
	std::string name;
	Model* parent;
	Processor* processor;	
	time_t sigma;
	std::string phase;
	std::vector<Port*> inputPorts; // vector 안에 Port 객체 대신 Port 객체의 포인터 저장 -> Port 객체를 vector에 저장할 때 복사 생성자를 호출하며 객체의 복사본을 저장하므로 시간과 메모리 측면에서 포인터 저장 방식이 보다 적합
	std::vector<Port*> outputPorts;

public:
	// (22.02.21) port 추가/반환 함수 필요

	virtual void test() {};
	std::string getName();
	Model* getParent();	
	void setProc(Processor* processor);
	Processor* getProc();	
	Model(std::string name, Model* parent); 
	Model();
};

