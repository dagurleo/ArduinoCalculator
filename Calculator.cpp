#include "Arduino.h"
#include "Calculator.h"

Calculator::Calculator() {

}
Calculator::~Calculator() {
	while(!valueStack.isEmpty()) {
		valueStack.pop();
	}
	while(!symbolStack.isEmpty()) {
		symbolStack.pop();
	}
}

void Calculator::AddToCalc(String val) {
	if(isDigit(val[0])) {
		temp += val;
		//Serial.println("Temp: ");
		//Serial.println(temp);
	}
	else if(val[0] == '=') {

	}
	else if(val == "+") {
		int smegma = temp.toInt();
		AddToValueStack(smegma);
		
		AddToSymbolStack('+');
		temp = "";
	}
	else if(val == "+") {
		int smegma = temp.toInt();
		AddToValueStack(smegma);
		
		AddToSymbolStack('-');
		temp = "";
	}
	else {
		Serial.println("Entered else");
		int smegma = temp.toInt();
		AddToValueStack(smegma);
		
		AddToSymbolStack(val[0]);
		temp = "";
	}
}
void Calculator::AddToValueStack(int val) {
	Serial.println("Added to Value stack");
	Serial.println(val);
	valueStack.push(val);
	
}
void Calculator::AddToSymbolStack(char val) {
	Serial.println("Added to symbol stack");
	Serial.println(val);
	symbolStack.push(val);
	
}
void Calculator::Clear() {
	while(!valueStack.isEmpty()) {
		valueStack.pop();
	}
	while(!symbolStack.isEmpty()) {
		symbolStack.pop();
	}
}

int Calculator::Calculate(){
	int result = valueStack.pop();
	int symbol = symbolStack.pop();
	switch(symbol) {
		case '+': 
			result += valueStack.pop();
			Serial.println("Plussing");
			break;
		case '-':
			result = valueStack.pop() - result;
			break;
		
	}
	valueStack.push(result);
	return result;
}	