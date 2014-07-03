#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H

#include<string>
using namespace std;

template<class T> class Set;
template<class T, class V> class TransitionFunction;
template<class T> class Tape;

//select which type of states the machine will use
typedef string StatesType;

//select the type of alphabet symbol
typedef string SymbolType;

//select the type of transition function argument
typedef string TransitionKeyType;

//select the type of transition function value
typedef string TransitionValueType;

typedef Set<SymbolType> AlphabetSet;
typedef Set<StatesType> StatesSet;
typedef Set<StatesType> FinalStatesSet;
typedef TransitionFunction<TransitionKeyType, TransitionValueType> TransitionF;
typedef Tape<SymbolType> MachineTape;

class TuringMachine
{
public:
	static TuringMachine& getInstance();
	
	AlphabetSet& getAlphabet() const;
	StatesSet& getStatesSet() const;
	FinalStatesSet& getFinalStates() const;

	TransitionF& getTransitionFunction() const;
	MachineTape& getTape() const;

	StatesType getStartState() const;
	void setStartState(StatesType);

	StatesType getCurrentState() const;
	void setCurrentState(StatesType);

protected:
	TuringMachine();

private:
	static TuringMachine* instance;

	StatesType startState;
	StatesType currentState;
	
	AlphabetSet* alphabet;
	StatesSet* states;
	FinalStatesSet* finalStates;

	TransitionF* transitionFunction;
	MachineTape* tape;
	
};

#endif