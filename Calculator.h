#include "StackArray.h"
#ifndef CALCULATOR_H	
#define CALCULATOR_H
#include <ctype.h>



using namespace std;

class Calculator {
public:
	Calculator();
	~Calculator();
	void AddToValueStack(int val);
	void AddToSymbolStack(char val);
	int Calculate();
	void Clear();
	void AddToCalc(String val);

private:
	StackArray<int> valueStack;
	StackArray<char> symbolStack;
	String temp = "";
};

#endif