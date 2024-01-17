// Message의 내용에 해당하며, 한 개의 Message 객체에는 다수의 Content 객체(또는 해당 객체에 관한 포인터)가 저장됨

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

