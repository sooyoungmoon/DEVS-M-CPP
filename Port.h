#pragma once
#include <string>
#include "Model.h"

class Model;

class Port
{
private:
	std::string type;
	std::string name;	
	Model* model; // associated model

public: 
	std::string getName();
	void setName(std::string pName);
	std::string getType();
	void setType(std::string pType);
	Model* getModel();
	void setModel(Model* aModel);
};

