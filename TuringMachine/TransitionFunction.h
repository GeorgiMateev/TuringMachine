#ifndef TRANSITIONFUNCTION_H
#define TRANSITIONFUNCTION_H

template<typename T, typename V>
class TransitionFunction
{
public:
	virtual void addRule(T,V) = 0;
	virtual V transite(T) = 0;
};

#endif