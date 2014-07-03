#ifndef DLLTAPE_H
#define DLLTAPE_H

#include"Tape.h"
#include"Element.h"
#include<sstream>

template<typename T>
class DLLTape : public Tape<T>
{
public:
	DLLTape();

	void add(T);

	T getPosition() const;
	void setPosition(T);

	T getBlank() const;
	void setBlank(T);

	void move(string);
	void moveLeft();
	void moveRight();

	void trim();
	void trimLeft();
	void trimRight();

	string toString() const;

private:
	Element<T>* first;
	Element<T>* last;
	Element<T>* position;

	T blank;

	int count;
};

template<typename T>
DLLTape<T>::DLLTape()
{
	this->count = 0;
	this->first = NULL;
	this->last = NULL;
	this->position = NULL;
}

template<typename T>
void DLLTape<T>::add(T value)
{
	Element<T>* e = new Element<T>();
	e->value = value;
	e->nextElement = NULL;
	e->previousElement = NULL;

	if(this->count == 0)
	{
		this->first = e;
		this->last = e;
		this->position = e;
	}
	else
	{
		this->last->nextElement = e;
		e->previousElement = this->last;
		this->last = e;
	}
	this->count++;	
}

template<typename T>
T DLLTape<T>::getPosition() const
{
	return this->position->value;
}

template<typename T>
void DLLTape<T>::setPosition(T value)
{
	this->position->value = value;
}

template<typename T>
T DLLTape<T>::getBlank() const
{
	return this->blank;
}

template<typename T>
void DLLTape<T>::setBlank(T value)
{
	this->blank = value;
}

template<typename T>
void DLLTape<T>::move(string direction)
{
	if(direction == "L") this->moveLeft();
	if(direction == "R") this->moveRight();
}

template<typename T>
void DLLTape<T>::moveLeft()
{
	if(this->position->previousElement != NULL)
	{
		this->position = this->position->previousElement;
	}
	else
	{
		Element<T>* e = new Element<T>();
		e->value = this->blank;
		e->nextElement = this->first;
		e->previousElement = NULL;
		this->first->previousElement = e;
		this->first = e;
		this->position = e;
		this->count++;
	}
}

template<typename T>
void DLLTape<T>::moveRight()
{
	if(this->position->nextElement != NULL)
	{
		this->position = this->position->nextElement;
	}
	else
	{
		Element<T>* e = new Element<T>();
		e->value = this->blank;
		e->previousElement = this->last;
		e->nextElement = NULL;
		this->last->nextElement = e;
		this->last = e;
		this->position = e;
		this->count++;
	}
}

template<typename T>
string DLLTape<T>::toString() const
{
	if(this->count == 0)
	{
		return "0";
	}

	Element<T>* current = this->first;

	ostringstream ss;
	ss<<this->count;

	string builder = ss.str() + " ";
	builder += current->value;

	while(current->nextElement != NULL)
	{
		current = current->nextElement;

		builder += " ";
		builder += current->value;
	}

	return builder;
}

template<typename T>
void DLLTape<T>::trim()
{
	this->trimLeft();
	this->trimRight();
}

template<typename T>
void DLLTape<T>::trimLeft()
{
	T currentValue = this->first->value;

	while(currentValue == this->blank)
	{
		Element<T>* firstPtr = this->first;
		this->first = this->first->nextElement;
		this->first->previousElement = NULL;

		delete firstPtr;
		this->count--;

		currentValue = this->first->value;
	}
}

template<typename T>
void DLLTape<T>::trimRight()
{
	T currentValue = this->last->value;

	while(currentValue == this->blank)
	{
		Element<T>* lastPtr = this->last;
		this->last = this->last->previousElement;
		this->last->nextElement = NULL;

		delete lastPtr;
		this->count--;

		currentValue = this->last->value;
	}
}

#endif