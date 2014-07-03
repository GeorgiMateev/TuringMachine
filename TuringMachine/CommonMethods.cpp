#include<sstream>
#include"CommonMethods.h"

bool CommonMethods::isEmptyFilePath(string path)
{
	return path.compare("") == 0 || path.compare("-") == 0;
}

void CommonMethods::splitTransitionRule
	(string rule, string& beginState, string& beginSymbol, string& endState, string& endSymbol, string& moveSymbol)
{
	istringstream stream(rule);

		stream>>beginState;
		stream>>beginSymbol;
		stream>>endState;
		stream>>endSymbol;
		stream>>moveSymbol;
}

void CommonMethods::splitTransitionResult(string result, string& state, string& symbol, string& directin)
{
	istringstream stream(result);

		stream>>state;
		stream>>symbol;
		stream>>directin;
}
