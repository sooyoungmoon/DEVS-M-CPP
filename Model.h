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
	std::vector<Port*> inputPorts; // vector �ȿ� Port ��ü ��� Port ��ü�� ������ ���� -> Port ��ü�� vector�� ������ �� ���� �����ڸ� ȣ���ϸ� ��ü�� ���纻�� �����ϹǷ� �ð��� �޸� ���鿡�� ������ ���� ����� ���� ����
	std::vector<Port*> outputPorts;

public:
	// (22.02.21) port �߰�/��ȯ �Լ� �ʿ�

	virtual void test() {};
	std::string getName();
	Model* getParent();	
	void setProc(Processor* processor);
	Processor* getProc();	
	Model(std::string name, Model* parent); 
	Model();
};

