#include"RunStartToEndStrategy.h"
#include"TuringMachine.h"
#include"Set.h"
#include"Tape.h"
#include"TransitionFunction.h"
#include"CommonMethods.h"

//for test
#include<iostream>
using namespace std;

void RunStartToEndStrategy::calculate(TuringMachine* machine)
{
	this->machine = machine;

	this->recursiveRun();
}

void RunStartToEndStrategy::recursiveRun()
{
	if(this->machine->getFinalStates().contains(this->machine->getCurrentState()))
	{
		return;
	}

	string key = this->machine->getCurrentState() + " " + this->machine->getTape().getPosition();

	string value = this->machine->getTransitionFunction().transite(key);
	if(value.compare("") == 0)
	{
		return;
	}

	string state, symbol, direction;
	CommonMethods::splitTransitionResult(value, state, symbol, direction);

	this->machine->setCurrentState(state);
	this->machine->getTape().move(direction);
	this->machine->getTape().setPosition(symbol);

	//cout<<this->machine->getTape().toString()<<endl;

	this->recursiveRun();
}