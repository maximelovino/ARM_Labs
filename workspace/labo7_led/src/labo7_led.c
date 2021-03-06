/*
===============================================================================
 Name        : labo7_led.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include "config_LPC1769.h"
#include <stdint.h>
#include <stdbool.h>

#include "../../MyLab_lib/inc/GPIO.h"
#include "cr_section_macros.h"

// TODO: insert other include files here

// TODO: insert other definitions and declarations here
uint8_t tabRGB[97];
void buildRGB(uint8_t r, uint8_t g,uint8_t b);
void ledSet(uint8_t r, uint8_t g,uint8_t b);

void ledSet(uint8_t r, uint8_t g,uint8_t b){
	buildRGB(r,g,b);
	LPC_SC->PCLKSEL0 = 1 << 2;
	//mode compteur
	T0CTCR = 0;
	//match register
	T0MCR = 1<<1;
	//on match à 3 coups de clock
	//period 10ns => 30*10 = 300ns
	T0MR0 = 30-1;
	T0TCR = 1; /* start the timer */

	LPC_SC->PCONP |= 1<<29;
	LPC_GPDMA->DMACConfig = 1;
	LPC_GPDMACH0->DMACCSrcAddr = tabRGB;

	FIO2DIR = 1 << 8;
	/*Problem here*/
	FIO2MASK = ~(1 << 8);
	//TODO put in define for FIO2PIN1 (8th pin of FIO2PIN)
	LPC_GPDMACH0->DMACCDestAddr = 0x2009C055;

	//26 source increment
	LPC_GPDMACH0->DMACCControl = (1<<26) + 97;

	LPC_SC->DMAREQSEL = 1;

	LPC_GPDMACH0->DMACCConfig = (001<<11) + (8 << 6) + 1;

}

void buildRGB(uint8_t r, uint8_t g,uint8_t b){
	tabRGB[0] = ~0;
	int i;

	for (i = 1; i <= 32; i++) {
		tabRGB[(i-1)*4+1] = ~1;
		tabRGB[(i-1)*4+1+1] = ~((g & (1 << i)) >> i);
		tabRGB[(i-1)*4+1+2] = ~0;
		tabRGB[(i-1)*4+1+3] = ~0;

		tabRGB[32+(i-1)*4+1] = ~1;
		tabRGB[32+(i-1)*4+1+1] = ~((r & (1 << i)) >> i);
		tabRGB[32+(i-1)*4+1+2] = ~0;
		tabRGB[32+(i-1)*4+1+3] = ~0;

		tabRGB[64+(i-1)*4+1] = ~1;
		tabRGB[64+(i-1)*4+1+1] = ~((b & (1 << i)) >> i);
		tabRGB[64+(i-1)*4+1+2] = ~0;
		tabRGB[64+(i-1)*4+1+3] = ~0;
	}

	//code 1 1100
	//code 0 1000
	//invert all tab at the end
}

int main(void) {

    // TODO: Don't choose hardware CS => Hardware is shit => VIVA SOFTWARE REVOLUCION

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter

    while(1) {
    	ledSet(240,240,240);
    }
    return 0 ;
}
