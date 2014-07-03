#include"FileIOService.h"
#include"Set.h"
#include"TransitionFunction.h"
#include"Tape.h"
#include"CommonMethods.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

FileIOService::FileIOService(string inputFile, string outputFile)
{
	this->inputFile = inputFile;
	this->outputFile = outputFile;
}

void FileIOService::readMachineInput(TuringMachine& machine)
{
	ifstream fin;
	fin.open(this->inputFile, ifstream::in);

	int alphabetSize = 0;
	fin>>alphabetSize;

	string blank;
	fin>>blank;

	machine.getTape().setBlank(blank);
	machine.getAlphabet().add(blank);

	for(int i = 0; i < alphabetSize - 1; i++)
	{
		string symbol;
		fin>>symbol;

		machine.getAlphabet().add(symbol);
	}

	int statesCount = 0;
	fin>>statesCount;

	string start;
	fin>>start;

	machine.setStartState(start);
	machine.setCurrentState(start);
	machine.getStatesSet().add(start);

	for(int i = 0; i < statesCount - 1; i++)
	{
		string symbol;
		fin>>symbol;

		machine.getStatesSet().add(symbol);
	}

	int finalsCount = 0;
	fin>>finalsCount;

	for(int i = 0; i < finalsCount; i++)
	{
		string symbol;
		fin>>symbol;

		machine.getFinalStates().add(symbol);
	}

	int rulesCount = 0;
	fin>>rulesCount;

	//get rid of the \n symbol in the end of the stream leaved by fin>>
	string line;
	std::getline(fin, line);

	for(int i = 0; i < rulesCount; i++)
	{		
		std::getline(fin, line);

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
	fin>>tapeLength;

	for(int i = 0; i < tapeLength; i++)
	{
		string tapeSymbol;
		fin>>tapeSymbol;

		machine.getTape().add(tapeSymbol);
	}

	fin.close();
}

void FileIOService::writeMachineOutput(TuringMachine& machine)
{
	ofstream fout;
	fout.open(this->outputFile);

	machine.getTape().trim();
	fout<<machine.getTape().toString()<<endl;

	fout.close();
}