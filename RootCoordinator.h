
// 22.01.29
// moontail
// Root-coordinator class

# ifndef _ROOT_COORD_
# define _ROOT_COORD_
#include "Processor.h"
class RootCoordinator : public Processor
{
private:
	static RootCoordinator* uniqInst;
	static int a;
	RootCoordinator();

public: 
	RootCoordinator* getInstance();

	void rcvDoneMsg(Message& doneMsg);

};

# endif