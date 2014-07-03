#ifndef STANDARTIOSERVICE_H
#define STANDARTIOSERVICE_H

#include"IOService.h"

class StandartIOService : public IOService
{
	public:
	virtual void readMachineInput(TuringMachine&);
	virtual void writeMachineOutput(TuringMachine&);
};

#endif