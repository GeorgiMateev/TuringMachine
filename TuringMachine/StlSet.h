#ifndef STLSET_H
#define STLSET_H

#include"Set.h"
#include<set>
using namespace std;

template<typename T>
class StlSet : public Set<T>
{
public:
	StlSet();

	void setCapacity(int);
	void add(T);
	bool contains(T&);

private:
	int capacity;

	std::set<T>* stlSet;
};

template<typename T>
StlSet<T>::StlSet()
{
	this->stlSet = new set<T>();
}

template<typename T>
void StlSet<T>::add(T element)
{
	this->stlSet->insert(element);
}

template<typename T>
void StlSet<T>::setCapacity(int c)
{
	this->capacity = c;
}

template<typename T>
bool StlSet<T>::contains(T& item)
{
	return this->stlSet->find(item) != this->stlSet->end();
}

#endif