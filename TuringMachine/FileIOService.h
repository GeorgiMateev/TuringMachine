#ifndef FILEIOSERVICE_H
#define FILEIOSERVICE_H

#include<string>
#include"IOService.h"
using namespace std;

class FileIOService : public IOService
{
public:
	FileIOService(string, string);

	virtual void readMachineInput(TuringMachine&);
	virtual void writeMachineOutput(TuringMachine&);

private:
	string inputFile;
	string outputFile;
};

#endif