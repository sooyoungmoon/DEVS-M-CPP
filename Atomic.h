#pragma once
#ifdef MODEL_EXPORTS
#define MODEL_API __declspec(dllexport)
#else 
#define MODEL_API __declspec(dllimport)
#endif

#include "Model.h"


class Atomic : public Model
{
public: 
	virtual Content output();
	virtual void intTransFn();
	virtual void extTransFn(time_t elapsedTime, std::vector<Content> contents);
	virtual time_t timeAdvFn(); // returns the value of sigma (the remaining time to the next internal event
	void hold_in(std::string phase, time_t duration);
	void keep_going(time_t elapsed_time); // keeping the current phase (with sigma updated)	
};

extern "C" { // C 함수 목록 (라이브러리 외부에서 호출) 
	MODEL_API void output_cmd(Atomic* am_inst, Content_str& con_str);
	MODEL_API void intTransFn_cmd(Atomic* am_inst);
	MODEL_API void extTransFn_cmd(Atomic* am_inst, time_t elapsedTime, Content con);
	MODEL_API time_t timeAdvFn(Atomic* am_inst);
}

