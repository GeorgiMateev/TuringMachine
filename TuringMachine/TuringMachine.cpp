#include"TuringMachine.h"
#include"StlSet.h"
#include"StlTransitionFunction.h"
#include"DLLTape.h"
#include"MachineStrategy.h"

TuringMachine* TuringMachine::instance = 0;

TuringMachine::TuringMachine()
{
	this->startState = "";

	this->alphabet = new StlSet<SymbolType>();
	this->states = new StlSet<StatesType>();
	this->finalStates = new StlSet<StatesType>();
	
	this->transitionFunction = new StlTransitionFunction<TransitionKeyType, TransitionValueType>();
	this->tape = new DLLTape<SymbolType>();
}

TuringMachine& TuringMachine::getInstance()
{
	if(TuringMachine::instance == NULL)
	{
		TuringMachine::instance = new TuringMachine();
	}
	return *TuringMachine::instance;
}


AlphabetSet& TuringMachine::getAlphabet() const
{
	return *(this->alphabet);
}

StatesSet& TuringMachine::getStatesSet() const
{
	return *(this->states);
}

FinalStatesSet& TuringMachine::getFinalStates() const
{
	return *(this->finalStates);
}

TransitionF& TuringMachine::getTransitionFunction() const
{
	return *(this->transitionFunction);
}

MachineTape& TuringMachine::getTape() const
{
	return *(this->tape);
}

void TuringMachine::setStartState(StatesType s)
{
	this->startState = s;
}

StatesType TuringMachine::getCurrentState() const
{
	return this->currentState;
}

void TuringMachine::setCurrentState(StatesType state)
{
	this->currentState = state;
}


