
#include "P.h"
#include <iostream>

using namespace std;

Content P::output() {

	// generates a new content with the data and
	// returns it

	Content res;
	string data;
	
	if (phase == "busy") {
		data = job_id;		
		res.setData(data);
	}	 

	return res;
}

void P::intTransFn() {
	if (phase == "busy") {
		phase = "passive";
		sigma = LLONG_MAX;
	}
	else {
		// do nothing
	}
}

void P::extTransFn(time_t elapsedTime, Content con) {
	// extracts and saves the job-id from the xMsg
		
	Port* port = con.getPort();
	string port_name = port->getName();

	if (port_name == "in") {

		if (phase == "passive") {
			job_id = con.getData();
			// hold in ( sigma = proc_time, phase = "busy")
			hold_in("busy", proc_time);
		}
		else { // if the model is not 'passive', it must be busy -> just update the sigma 
			keep_going(elapsedTime);
		}
	}
	else { 
		// if the input port is wrong, print a warning message
		cout << "Warning: unexpected input port: " << port_name << endl;
	}

	return;
}

time_t P::timeAdvFn() { 
	return sigma;
}


P* CreatePModel()
{
	std::cout << "P model °´Ã¼ »ý¼º" << std::endl;
	return new P();
}