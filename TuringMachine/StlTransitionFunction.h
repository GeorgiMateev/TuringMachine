#ifndef STLTRANSITIONFUNCTION_H
#define STLTRANSITIONFUNCTION_H

#include"TransitionFunction.h"
#include<map>
using namespace std;

template<typename T, typename V>
class StlTransitionFunction : public TransitionFunction<T,V>
{
public:
	StlTransitionFunction();

	void addRule(T,V);
	V transite(T);

private:
	std::map<T, V>* stlMap;
};

template<typename T, typename V>
StlTransitionFunction<T,V>::StlTransitionFunction()
{
	this->stlMap = new std::map<T,V>();
}

template<typename T, typename V>
void StlTransitionFunction<T,V>::addRule(T request, V response)
{
	this->stlMap->insert(std::pair<T, V>(request, response));
}

template<typename T, typename V>
V StlTransitionFunction<T, V>::transite(T request)
{
	if(this->stlMap->find(request) == this->stlMap->end())
	{
		return V();
	}

	return this->stlMap->operator[](request);
}

#endif