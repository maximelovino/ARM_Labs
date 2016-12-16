/*
===============================================================================
 Name        : labo2_ASM.c
 Author      : D. Bechevet, V. Pilloux, A. Lescourt, F. Vannel
 Copyright   : HES-SO hepia
 Year        : 2015-2016
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

extern uint32_t funcexo1(uint32_t, uint32_t);
extern uint32_t funcexo2(uint32_t);
extern uint32_t funcexo3(uint32_t);
extern uint64_t funcexo4(uint64_t, uint32_t);

uint32_t function1_bonus(uint32_t val1, uint32_t val);
uint32_t function2_bonus(uint32_t val1);

/* global variables */
uint8_t exo;		// change this variable with the exercise number you want to test


/***********************************
 * function     : function1_bonus
 * arguments    : Unsigned Int 32, Unsigned Int 32
 * return value : Unsigned Int 32
 * Bonus - Code in C for the function 1
 ***********************************/
uint32_t function1_bonus(uint32_t val1, uint32_t val2)
{
	if (val1<val2) {
		return function1_bonus(val2,val1);
	}
	return val1-val2; // replace 0 by the name of your variable to be returned
}

/***********************************
 * function     : function2_bonus
 * arguments    : Unsigned Int 32
 * return value : Unsigned Int 32
 * Bonus - Code in C for the function 2
 ***********************************/
uint32_t function2_bonus(uint32_t val1)
{
	return 0; // replace 0 by the name of your variable to be returned
}

int main(void)
{
	exo = 4;    // change this number with the exercise number you want to test

	uint32_t a,b,c;
	uint8_t  i;

	uint64_t B_64;

	while (1)
	{
		switch(exo){					// select the function corresponding to the exercise to test

		case 1 :
			b = funcexo1(128,103);    // try with another values
			c = funcexo1(8,24);       // try with another values

			a = function1_bonus(b,c);	  // Bonus exercise 1

			break;
		case 2 :
			a = funcexo2(1000);          // try with another value

			a = function2_bonus(a);   // Bonus exercise 2

			break;

		case 3 :
			a = funcexo3(5);          // try with another value
			break;

		case 4 :
			B_64=0x6000000A50000009;	// try with another value
			for (i=0; i<32; i++)
				B_64=funcexo4(B_64,1);

			B_64=0x7;					// try with another value
			for (i=0; i<32; i++)
				B_64=funcexo4(B_64,0);

			B_64=0xFE00000D40000089;	// try with another value
			B_64=funcexo4(B_64,2);
			break;

		}
	}
	return 0 ;
}
