#include "Atomic.h"

using namespace std;

void Atomic::hold_in(string phase, time_t duration) {
	this->sigma = duration;
	this->phase = phase;
}

void Atomic::keep_going(time_t elapsed_time) {
	
	if (sigma != LLONG_MAX) {
		this->sigma = sigma - elapsed_time;
	}
}

/* interface functions to access sample model objects */

void output_cmd(Atomic* am_inst, Content_str& con_str) {
	Content con =  am_inst->output();

	// store the necessary information into the con_str, a reference variable of Content_str type
	

	Port* port = con.getPort();
	Model* model = port->getModel();

	string name = port->getName();

	string port_name = port->getName();
	const char* port_name_ch = port_name.c_str();

	string model_name = model->getName();
	const char* model_name_ch = model_name.c_str();

	string data = con.getData();
	const char* data_ch = data.c_str();

	/* allocate memory */
	int port_name_len = strlen(port_name_ch) + 1;
	int model_name_len = strlen(model_name_ch) + 1;
	int data_str_len = strlen(data_ch) + 1;

	con_str.port_name = new char[port_name_len];
	con_str.model_name = new char[model_name_len];
	con_str.data = new char[data_str_len];

	/* copy strings */
	strcpy_s(con_str.port_name, port_name_len, port_name_ch);
	strcpy_s(con_str.model_name, model_name_len, model_name_ch);
	strcpy_s(con_str.data, data_str_len, data_ch);

	return;
}

void intTransFn_cmd(Atomic* am_inst) {
	am_inst->intTransFn();
}

void extTransFn_cmd(Atomic* am_inst, time_t elapsedTime, Content con) {
	am_inst->extTransFn(elapsedTime, con);

}

time_t timeAdvFn(Atomic* am_inst) {
	return am_inst->timeAdvFn();
}


