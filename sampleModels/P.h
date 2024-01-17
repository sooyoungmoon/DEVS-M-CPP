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
	Content output(); // ��� �Լ�
	void intTransFn(); // ���� ���� ���� �Լ�
	void extTransFn(time_t elapsedTime, Content con); // �ܺ� ���� ���� �Լ�
	time_t timeAdvFn(); // �ð� ���� �Լ� 	
};

extern "C" {
	// factory �Լ�
	MODEL_DLL P* CreatePModel();



}

#endif
