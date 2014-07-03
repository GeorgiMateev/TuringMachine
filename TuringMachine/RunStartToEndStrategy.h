#ifndef RUNSTARTTOENDSTRATEGY_H
#define RUNSTARTTOENDSTRATEGY_H

#include"MachineStrategy.h"

class RunStartToEndStrategy : public MachineStrategy
{
public:
	void calculate(TuringMachine*);

private:	
	void recursiveRun();

	TuringMachine* machine;
};

#endif