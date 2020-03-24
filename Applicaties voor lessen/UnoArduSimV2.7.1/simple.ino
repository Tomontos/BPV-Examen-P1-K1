#include <Servo.h>
Servo servo;
int snelheid = 90;
const int buttonHoger = 3; // Button Hoger
const int buttonReset = 4; // Button Reset
const int buttonLager = 5; // Button Lager

int buttonHogerV = 0;
int buttonResetV = 0;
int buttonLagerV = 0;

void setup(){
	Serial.begin(9600);
	servo.attach(2);	
}

void loop(){
	buttonHogerV = digitalRead(buttonHoger);
	buttonResetV = digitalRead(buttonReset);
	buttonLagerV = digitalRead(buttonLager);
	
	if(buttonHogerV == 0){
		if(snelheid < 180){
			snelheid = snelheid + 1;
		}
	}	
	if(buttonResetV == 0){
		snelheid = 90;
	}	
	if(buttonLagerV == 0){
		if(snelheid > 0){
			snelheid = snelheid - 1;
		}
	}	
	servo.write(snelheid);
	delay(100);		
}
