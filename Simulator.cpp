#ifndef _SIMULATOR_
#define _SIMULATOR_

#include "Simulator.h"
#include "Coordinator.h"
#include "Atomic.h"
#include <string>

using namespace std;

void Simulator::rcvStarMsg(Message* starMsg) {

	/* processing a star msg */
	// 0. check if the time in the received starMsg is the same as tN. If not, drop the message and do not process it
	// 1. call the output function of the associated DEVS model -> get the content object as a return value
	// 2. create a Y message using the content and send it to the parent processor
	// 3. execute the internal transition function of the DEVS model
	// 4. update the TN and TL 
	// 5. construct a Done message and forward it to the parent processor


	time_t time = starMsg->getMsgTime();

	if (time == this->tN) {
		Atomic* devs_model = dynamic_cast<Atomic*> (this->model);

		Content_str* con_str = new Content_str;

		// 1. call the output function of the associated DEVS model -> get the content object as a return value
		output_cmd(devs_model, *con_str); // calling the interface function 'output_cmd' to get the output of the model

		// get necessary information from the con_str and
		// create a new Content object

		Content con;

		// get the address of Port object using model_name and port_name (both are char* type)

		string data(con_str->data); // create string object using const char*)
		con.setData(data);

		// 2. create a Y message using the content and send it to the parent processor
		Message* yMsg = new Message();
		yMsg->setMsgType("Y");
		yMsg->setMsgTime(time);
		yMsg->setSrcModel(this->model);
		yMsg->addContent(con);
		
		assert(parent != nullptr); // a simulator should have a parent processor (i.e., coordinator)

		Coordinator* coord = dynamic_cast<Coordinator*> (this->parent);
		coord->rcvYMsg(*yMsg); // (22.01.22) we need to use Move semantics for time-efficient argument passing! (and to avoid memory leak also) 

		// 3. execute the internal transition function of the DEVS model
		devs_model->intTransFn();

		// 4. update the TN and TL 
		tL = tN;
		tN = tN + devs_model->timeAdvFn();

		// 5. creates a done msg and send it to the parent coordinator
		sndDoneMsg(time);


		// memoery deallocation

		yMsg->clearContents();
		delete yMsg;

		

		delete con_str->port_name;
		delete con_str->model_name;
		delete con_str->data;
		delete con_str;
	}

}


void Simulator::rcvXMsg(Message* xMsg) {
	
	time_t time = xMsg->getMsgTime();

	// 0. check the received time is between tL and tN
	if ( tL <= time && time <= tN) {
		// 1. compute the elapsed time
		time_t elapsed_time = time - tL;

		// 2. send the content to the associated model
		std::vector<Content> contents = xMsg->getContents();

		Atomic* devs_model = dynamic_cast<Atomic*> (this->model);
		devs_model->extTransFn(elapsed_time, contents);

		// 3. update the tL and tN
		this->tL = time;
		this->tN = this->tL + devs_model->timeAdvFn();
		
		// 4. creates a done msg and send it to the parent coordinator
		sndDoneMsg(time);

		
	}
}


void Simulator::sndYMsg(Message* yMsg) {

}


void Simulator::sndDoneMsg(time_t time) {
	// creates a done msgand send it to the parent coordinator

	Message* doneMsg = new Message();
	doneMsg->setMsgTime(time);
	doneMsg->setSrcModel(this->model);

	Coordinator* coord = dynamic_cast<Coordinator*> (this->parent);
	coord->rcvDoneMsg(*doneMsg); // 

	//memory deallocation
	assert(doneMsg->getContents().size() == 0); // done msg should have no content in it
	delete doneMsg;
}

#endif