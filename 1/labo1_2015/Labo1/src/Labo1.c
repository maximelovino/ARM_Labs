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

int main(void) {
	uint8_t i,j;
	char *texte = "HelloWorld";

	// first loop
	j=0;
	for (i=0; i<100; i++)
	{
		if (texte[j]!=0)
		{
			tab1[i]=texte[j];
			j++;
		}
		else{
			j=0;
		}
	}

	// second loop
	j=0;
	i=0;
	do
	{
		do
		{
			if (texte[j]!=0)
			{
				tab2[i]=texte[j];
				j++;
			}
			else
			{
				j=0;
			}
			i++;
		}while (texte[j]!=0);
	}while (i<100);

// exercice fourmi de Langton

	init_LCD();
	Display_Picture32(image);

	while (1)
	{}
} /* end of main */

