/*
===============================================================================
 Name        : labo5_Interruption_GPIO_TIMER.c
 Author      : D. Bechevet, V. Pilloux, A. Lescourt, F. Vannel
 Copyright   : HES-SO hepia
 Year        : 2015-2016
===============================================================================
 */


#include "config_LPC1769.h"
#include <stdint.h>
#include <stdbool.h>

#include "../../MyLab_lib/inc/GPIO.h"

/* function prototypes */
void exercice1(void);
void exercice2(void);
void exercice3(void);
void exercice4(void);
void Led8SetState (uint8_t value);
void init_Interruption();
void initTimer();
/* global variables */
uint8_t exo;		// change this variable with the exercise number you want to test
uint8_t value = 1;
uint8_t i = 1;
int timerForMovement = 600;
int left = 1;
/***********************************
 * function     : exercice1
 * arguments    : none
 * return value : none
 *   COMPTEUR IRQ GPIO
 ***********************************/
void exercice1(void)
{
	Led8SetState(value);
}

/***********************************
 * function     : exercice2
 * arguments    : none
 * return value : none
 *   CHENILLARD IRQ GPIO
 ***********************************/
void exercice2(void)
{
	Led8SetState(i);
}

/***********************************
 * function     : exercice3
 * arguments    : none
 * return value : none
 *   CHENILLARD IRQ TIMER
 ***********************************/
void exercice3(void)
{
	Led8SetState(i);
}

/***********************************
 * function     : exercice4
 * arguments    : none
 * return value : none
 *   Click et double Click
 ***********************************/
void exercice4(void)
{

}

void init_Interruption(){
	ISER0 = 1 << 21;
	IO2INTEnR = 1 << 10;
	IO0INTEnR = 1 << 19;

	ISER0 = 1 << 1;
	ISER0 = 1 << 2;
	initTimer();
}

void initTimer(){
	T0PR = 25000;
	//timer 1 is for joystick
	T1PR = 25000;
	//Forcer le mode compteur utilisant la base de temps
	T0CTCR = 0;
	T1CTCR = 0;
	//Choisir un MATCH register et l’activer pour qu’il génère une interruption à chaque égalité avec le compteur.
	T0MCR = 1;
	T1MCR = 1;
	//1 = quand match mr0 => interruption
	T0MR0 = 600;
	//10ms for button poll
	T1MR0 = 10;
	T0TCR = 1;
	T1TCR = 1;
}

void TIMER0_IRQHandler(){
	T0MR0 += timerForMovement;
	T0IR = 1;
	if(left){
		i = i << 1;
		if (i == 0) i = 1;
	}else{
		i = i >> 1;
		if(i == 0) i = 1 << 7;
	}

}

void TIMER1_IRQHandler(){
	T1MR0 +=10;

	//19 center
	//20 up
	//21 right
	//22 down
	//23 left
	//center
	if (fallingEdgeJoystick(0)){
		//not working
		i = SwitchGetState();
	}
	//up
	if (fallingEdgeJoystick(1)){
		timerForMovement /= 2;
	}
	//right
	if(fallingEdgeJoystick(2)){
		left = 0;
	}
	//down
	if (fallingEdgeJoystick(3)){
		timerForMovement *= 2;
	}
	//left
	if(fallingEdgeJoystick(4)){
		left = 1;
	}
	//not working very well either
	if (timerForMovement == 0){
		timerForMovement = 1;
	}
	T1IR = 1;
}

void EINT3_IRQHandler(){
	if ((IO2INTStatR & (1 << 10)) != 0) {
		IO2INTClr = 1 << 10;
		value++;
	}
	if ((IO0INTStatR & (1 << 19)) != 0){
		IO0INTClr = 1 <<19;
		value--;
	}

}


/***********************************
 * function     : main
 * arguments    : none
 * return value : none
 * Startup function
 ***********************************/
int main(void) {
	exo = 3;    // change this number with the exercise number you want to test
	init_Interruption();
	while (true)
	{
		switch(exo){					// select the function corresponding to the exercise to test
		case 1 : exercice1(); break;
		case 2 : exercice2(); break;
		case 3 : exercice3(); break;
		case 4 : exercice4(); break;
		}

	}
}
