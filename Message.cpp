#include "Message.h"

using namespace std;


void Message::setMsgType(std::string type) {
	this->type = type;
}


std::string Message::getMsgType() {
	return this->type;
}


void Message::setMsgTime(time_t time) {
	this->time = time;
}


time_t Message::getMsgTime() {
	return this->time;
}



void Message::setSrcModel(Model* model) {
	this->src_model = model;
}


Model* Message::getSrcModel() {
	return this->src_model;
}


 
std::vector<Content> Message::getContents() {
	return this->contents;
}

 
void Message::addContent(Content content) {
	this->contents.emplace_back(content);
}

void Message::clearContents() { // free & remove all the contents in the message	

	
	contents.clear();
}