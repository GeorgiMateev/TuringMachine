#include<iostream>
#include<string>
#include"IOServiceFactory.h"
#include"StandartIOService.h"
#include"FileIOService.h"
#include"CommonMethods.h";
using namespace std;

IOService& IOServiceFactory::createService()
{
	string inputFilePath;
	string outputFilePath;

	getline(cin, inputFilePath);
	getline(cin, outputFilePath);

	if(CommonMethods::isEmptyFilePath(inputFilePath) ||
		CommonMethods::isEmptyFilePath(outputFilePath))
	{
		IOService* service = new StandartIOService();
		return *service;
	}
	else
	{
		IOService* service = new FileIOService(inputFilePath, outputFilePath);
		return *service;
	}
}