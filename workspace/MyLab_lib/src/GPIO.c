/*
 * GPIO.c
 *
 *  Created on: 1 déc. 2016
 *      Author: lovinom
 */

#include "GPIO.h"


bool valuesJoystick[5];


void Led8SetState (uint8_t value){
	FIO2DIR = 0xff;
	FIO2CLR = 0xff;
	FIO2SET = value;
}

void init(void)
{
	FIO2DIR = 0xFF;
	FIO1DIR = 0x0000;
}

void delai(uint16_t delai){
	int valueFor1000 = 1e5;
	int i;
	for (i = 0; i < (delai/1000)*valueFor1000; ++i);
}

void LedSetState (uint8_t led, bool state){
	FIO2DIR = 0xff;
	FIO2MASK = !(1<<led);
	FIO2PIN = state<<led;
}

bool JoystickGetState (uint8_t pos){
	return !((FIO1PIN>>(19+pos)) & 1);
}

bool fallingEdgeJoystick (uint8_t pos){
	if(pos > 4) return false;

	bool current = JoystickGetState(pos);
	bool val = false;
	if(!current && valuesJoystick[pos]){
		val = true;
	}
	valuesJoystick[pos] = current;
	return val;
}

uint8_t SwitchGetState (void){
	FIO2DIR = 0x00;
	return (uint8_t) FIO2PIN;
}


