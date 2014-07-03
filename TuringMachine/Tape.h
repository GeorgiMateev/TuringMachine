#ifndef TAPE_H
#define TAPE_H

#include<string>
using namespace std;

template<typename T>
class Tape
{
public:
	virtual void add(T) = 0;

	virtual T getPosition() const = 0;
	virtual void setPosition(T) = 0;

	virtual void move(string) = 0;
	virtual void moveLeft() = 0;
	virtual void moveRight() = 0;

	virtual T getBlank() const = 0;
	virtual void setBlank(T) = 0;

	virtual void trimLeft() = 0;
	virtual void trimRight() = 0;
	virtual void trim() = 0;

	virtual string toString() const = 0;
};

#endif