/*
===============================================================================
 Name        : labo3_ASM2.c
 Author      : D. Bechevet, V. Pilloux, A. Lescourt, F. Vannel
 Copyright   : HES-SO hepia
 Year        : 2015-2016
===============================================================================
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

typedef struct  {
	int32_t a;
	int8_t b;
	int16_t c;
	int8_t d;
	int32_t e;
} numbers_t;


extern uint32_t funcexo1(uint32_t* valA, uint32_t* valB);
extern uint32_t funcexo2(uint32_t* tabA, uint32_t* tabB);
extern uint32_t add_struct(numbers_t s);

/* global variables */
uint8_t exo;

int main(void) {
	exo = 3;    // change this number with the exercise number you want to test

	uint32_t valeurs_test[] = {1,23,17,4,0xFFFFFFF0,100};
	uint32_t *a;
	uint32_t *b;
	uint32_t res;

	uint32_t A1_vect[10] = {5,2,3,4,6,10,0x256,800,256,0x1234};
	uint32_t A2_vect[10] = {5,2,3,4,6,10,256,0xFEDCBA98,256,0x123456};
	uint32_t B_vect[10];
	uint32_t ok;

	numbers_t s1 = {1,2,3,4,5};
	numbers_t s2 = {-1,-2,-3,-4,-5};

	while (1)
	{
		switch(exo){					// select the function corresponding to the exercise to test
		case 1 :
			a = &valeurs_test[0];       /* point our pointer at the first integer in our array */
			b = &valeurs_test[1];		/* point our pointer at the second integer in our array */
			res = funcexo1(a,b);
			a = &valeurs_test[2];       /* point our pointer at the third integer in our array */
			b = &valeurs_test[4];		/* point our pointer at the fifth integer in our array */
			res = funcexo1(a,b);

			break;
		case 2 :
			ok = funcexo2(A1_vect,B_vect);          // B_vect = 2* A1_vect
			ok = funcexo2(A2_vect,B_vect);          // B_vect = 2* A2_vect
			break;
		case 3 :
			res=add_struct(s1);
			res=add_struct(s2);
			break;
		}

	}
}
