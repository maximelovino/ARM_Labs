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
void buildRGB(uint32_t r, uint32_t g,uint32_t b);
void ledSet(uint32_t r, uint32_t g,uint32_t b);

void ledSet(uint32_t r, uint32_t g,uint32_t b){
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

	LPC_SC->PCONP = 1<<1;
	LPC_GPDMA->DMACConfig = 1;
	LPC_GPDMACH0->DMACCSrcAddr = tabRGB;

	FIO2DIR = 1 << 8;
	/*Problem here*/
	FIO2MASK = 1 << 8;
	//TODO put in define for FIO2PIN1 (8th pin of FIO2PIN)
	LPC_GPDMACH0->DMACCDestAddr = 0x2009C055;

	//26 source increment
	LPC_GPDMACH0->DMACCControl = (1<<26) + 97;

	LPC_SC->DMAREQSEL = 1;

	LPC_GPDMACH0->DMACCConfig = (001<<11) + (8 << 6) + 1;
}

void buildRGB(uint32_t r, uint32_t g,uint32_t b){
	tabRGB[0] = ~0;
	int i;
	for (i = 1; i < 33; ++i) {
		tabRGB[i] = ~((r & (1 << i)) >> i);
		tabRGB[i+32] = ~((g & (1 << i)) >> i);
		tabRGB[i+64] = ~((b & (1 << i)) >> i);
	}

}

int main(void) {

    // TODO: Don't choose hardware CS

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
    	ledSet(255,0,255);
    }
    return 0 ;
}
