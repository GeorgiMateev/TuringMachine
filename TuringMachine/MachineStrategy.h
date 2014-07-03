#ifndef MACHINESTRATEGY_H
#define MACHINESTRATEGY_H

class TuringMachine;

class MachineStrategy
{
public:
	virtual void calculate(TuringMachine*) = 0;

};

#endif