#include "Content.h"

using namespace std;

Port* Content::getPort() {
	return this->port;
}

void Content::setPort(Port* aPort) {
	this->port = aPort;
}

void Content::setData(string data) {
	this->data = data;
}

void Content::clearData() {	
	this->data = "";
}

string Content::getData() {
	return this->data;
}

