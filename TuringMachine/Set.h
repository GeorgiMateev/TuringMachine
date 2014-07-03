#ifndef SET_H
#define SET_H

template<typename T>
class Set
{
public:	
	virtual void add(T) = 0;
	virtual bool contains(T&) = 0;
};

#endif
