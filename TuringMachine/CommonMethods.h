#ifndef COMMONMETHODS_H
#define COMMONMETHODS_H

#include<string>
using namespace std;

class CommonMethods
{
public:
	static bool isEmptyFilePath(string);

	static void splitTransitionRule(string, string&, string&, string&, string&, string&);

	static void splitTransitionResult(string, string&, string&, string&);
};

#endif