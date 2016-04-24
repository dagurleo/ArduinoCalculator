//ArdinoCalc.ino
#include <Calculator.h>
#include <LiquidCrystal.h>


Calculator calc;
int led = 13;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//Potentiometer globals
const int potPin = 5;
int val = 0;
//Potentiometer button globals
int inButtonPin = 6;
bool inButtonPinBeenPressed = false;
int inButtonPinState = 0;
//+ button globals
int plusButtonPin = 9;
bool plusButtonPinBeenPressed = false;
int plusButtonPinState = 0;
//- button globals
int minusButtonPin = 8;
bool minusButtonPinBeenPressed = false;
int minusButtonPinState = 0;
//= button globals
int equalsButtonPin = 7;
bool equalsButtonPinBeenPressed = false;
int equalsButtonPinState = 0;

String lcdText;
void setup() {
  // put your setup code here, to run once:
  
	Serial.begin(9600);
	lcd.begin(16,2);
	Serial.println("Reading Potentiometer");
	pinMode(inButtonPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    val = analogRead(potPin);
    //Serial.println(val);
    inButtonPinState = digitalRead(inButtonPin);
    plusButtonPinState = digitalRead(plusButtonPin);
    minusButtonPinState = digitalRead(minusButtonPin);
    equalsButtonPinState = digitalRead(equalsButtonPin);
    if(inButtonPinState == LOW && inButtonPinBeenPressed == false) {
    	int number = potToInt(val);
    	//lcdText = lcdText + number;
    	calc.AddToValueStack(number);
    	inButtonPinBeenPressed = true;
    	lcd.print(number);
    	delay(100);
    } else {
    	inButtonPinBeenPressed = false;
    }

    if(plusButtonPinState == LOW && plusButtonPinBeenPressed == false) {
    	calc.AddToSymbolStack('+');
    	lcd.print("+");
    	plusButtonPinBeenPressed = true;
    	delay(100);
    } else {
    	inButtonPinBeenPressed = false;
    }

    if(minusButtonPinState == LOW && minusButtonPinBeenPressed == false) {
    	calc.AddToSymbolStack('-');
    	lcd.print("-");
    	minusButtonPinBeenPressed = true;
    	delay(100);
    } else {
    	inButtonPinBeenPressed = false;
    }

    if(equalsButtonPinState == LOW && equalsButtonPinBeenPressed == false) {
    	int equals = calc.Calculate();
    	Serial.print("=");
    	Serial.print(equals);
    	lcd.print("=");
    	delay(500);
    	lcd.clear();
    	lcd.print(equals);


    	equalsButtonPinBeenPressed = true;
    } else {
    	equalsButtonPinBeenPressed = false;
    }




    delay(100);
}

int potToInt(int potVal) {
	return potVal/100;

}