#ifndef IOSERVICEFACTORY_H
#define IOSERVICEFACTORY_H

class IOService;

class IOServiceFactory
{
public:
	static IOService& createService();
};

#endif