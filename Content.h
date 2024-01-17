// Message�� ���뿡 �ش��ϸ�, �� ���� Message ��ü���� �ټ��� Content ��ü(�Ǵ� �ش� ��ü�� ���� ������)�� �����

#pragma once
#include "Port.h"
#include "Model.h"
#include <vector>
#include <string>

class Port;
class Model;

class Content
{
private:
	Port* port;	
	std::string data;
public:
	Port* getPort();
	void setPort(Port* aPort);
	void setData(std::string data);
	void clearData();
	std::string getData();
};

struct Content_str { // used by a model object to return value when its output_cmd() function is called
	char* model_name;
	char* port_name;
	char* data; 
};

