/*
===============================================================================
 Name        : Labo1.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include "lcd.h"

/* Global variables */
char tab1[100];
char tab2[100];
uint32_t image[128]={0x7C, 0x82, 0x129, 0x141, 0x141, 0x129, 0x82, 0x7C};

//return the result of the test, will be 0 if the case is not on
int isCaseOn(uint32_t* image,int x,int y){
	return image[x] & (1<<y);
}

int main(void) {

	int x,y,dir;
	//dir 0 en haut, 1 droite, 2 bas, 3 gauche

	x = 64;
	y = 16;
	dir = 0;



// exercice fourmi de Langton

	init_LCD();
	Display_Picture32(image);

	while (1)
	{
		if (isCaseOn(image,x,y)) {
			dir++;
		}else{
			dir--;
		}
		//Because mod in C is broken
		if(dir<0){
			dir+=4;
		}

		dir = dir%4;

		image[x]^=(1<<y);

		switch (dir) {
			case 0:
				y--;
				break;
			case 1:
				x++;
				break;
			case 2:
				y++;
				break;
			case 3:
				x--;
				break;
			default:
				break;
		}
		if(x<0){
			x+=127;
		}

		if(y<0){
			y+=32;
		}

		x%=127;
		y%=31;
//		x++;
//		x %= 127;
//		image[x] ^= (1<<y);
		Delay(100);
		Display_Picture32(image);
	}
} /* end of main */



