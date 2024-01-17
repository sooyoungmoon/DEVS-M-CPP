#ifndef _P_
#define _P_
#ifdef MODEL_EXPORTS
#define MODEL_DLL __declspec(dllexport)
#else 
#define MODEL_DLL __declspec(dllimport)
#endif

#include "Atomic.h"
#include <string>

class P : public Atomic
{
private:
	// state variables
	std::string job_id;	
	int proc_time = 5; // the time for processing a job 

public:
	Content output(); // 출력 함수
	void intTransFn(); // 내부 상태 정의 함수
	void extTransFn(time_t elapsedTime, Content con); // 외부 상태 전이 함수
	time_t timeAdvFn(); // 시간 전진 함수 	
};

extern "C" {
	// factory 함수
	MODEL_DLL P* CreatePModel();



}

#endif
