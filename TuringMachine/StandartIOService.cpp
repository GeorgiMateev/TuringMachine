#include"StandartIOService.h"
#include"Set.h"
#include"TransitionFunction.h"
#include"Tape.h"
#include"CommonMethods.h"
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

void StandartIOService::readMachineInput(TuringMachine& machine)
{
	int alphabetSize = 0;
	cin>>alphabetSize;

	string blank;
	cin>>blank;

	machine.getTape().setBlank(blank);
	machine.getAlphabet().add(blank);

	for(int i = 0; i < alphabetSize - 1; i++)
	{
		string symbol;
		cin>>symbol;

		machine.getAlphabet().add(symbol);
	}

	int statesCount = 0;
	cin>>statesCount;

	string start;
	cin>>start;

	machine.setStartState(start);
	machine.setCurrentState(start);
	machine.getStatesSet().add(start);

	for(int i = 0; i < statesCount - 1; i++)
	{
		string symbol;
		cin>>symbol;

		machine.getStatesSet().add(symbol);
	}

	int finalsCount = 0;
	cin>>finalsCount;

	for(int i = 0; i < finalsCount; i++)
	{
		string symbol;
		cin>>symbol;

		machine.getFinalStates().add(symbol);
	}

	int rulesCount = 0;
	cin>>rulesCount;

	//get rid of the \n symbol in the end of the stream leaved by cin>>
	string line;
	std::getline(cin, line);

	for(int i = 0; i < rulesCount; i++)
	{		
		std::getline(cin, line);

		string beginState;
		string beginSymbol;
		string endState;
		string endSymbol;
		string moveSymbol;

		CommonMethods::splitTransitionRule(line, beginState, beginSymbol, endState, endSymbol, moveSymbol);

		string request = beginState + " " + beginSymbol;
		string response = endState + " " + endSymbol + " " + moveSymbol;

		machine.getTransitionFunction().addRule(request, response);
	}

	int tapeLength = 0;
	cin>>tapeLength;

	for(int i = 0; i < tapeLength; i++)
	{
		string tapeSymbol;
		cin>>tapeSymbol;

		machine.getTape().add(tapeSymbol);
	}
}

void StandartIOService::writeMachineOutput(TuringMachine& machine)
{
	machine.getTape().trim();
	cout<<machine.getTape().toString()<<endl;
}