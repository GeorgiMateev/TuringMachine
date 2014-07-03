#ifndef ELEMENT_H
#define ELEMENT_H

template<typename T>
struct Element
{
public:
	T value;
	Element<T>* nextElement;
	Element<T>* previousElement;		
};

#endif