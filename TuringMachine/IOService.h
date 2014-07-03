#ifndef IOSERVICE_H
#define IOSERVICE_H

#include"TuringMachine.h"

class IOService
{
public:
	virtual void readMachineInput(TuringMachine&) = 0;
	virtual void writeMachineOutput(TuringMachine&) = 0;
};

#endif