#include"IOServiceFactory.h"
#include"TuringMachine.h"
#include"IOService.h"
#include"RunStartToEndStrategy.h"

class MachineStrategy;

void main()
{
	TuringMachine& machine = TuringMachine::getInstance();

    IOService& reader = IOServiceFactory::createService();

	reader.readMachineInput(machine);

	RunStartToEndStrategy* strategy = new RunStartToEndStrategy();

	strategy->calculate(&machine);
	
	reader.writeMachineOutput(machine);
};