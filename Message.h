#ifndef _MESSAGE_
#define _MESSAGE_
#include "Content.h"
#include <Vector>

class Content;
class Model;


class Message
{
private:
	std::vector<Content> contents;
	std::string type; 
	time_t time;
	Model* src_model; 

public:	
	void setMsgType(std::string type);
	std::string getMsgType();
	
	void setMsgTime(time_t time);
	time_t getMsgTime();

	void setSrcModel(Model* model);
	Model* getSrcModel();

	
	std::vector<Content> getContents();	
	void addContent(Content content);
	void clearContents();


};

#endif