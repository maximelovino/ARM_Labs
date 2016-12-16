/*
===============================================================================
 Name        : labotest1_iti_jour_B.c
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

int32_t funcexo1(char* number_str);
int32_t funcexo2(char* nb1, char* nb2, char op);

int main(void) {

	int32_t number;
	int32_t result;

    while(1) {

    	number = funcexo1("314");    // 314
    	number = funcexo1("24");     // 24
    	number = funcexo1("01010 "); // 1010
    	number = funcexo1("27183");  // 27183
    	number = funcexo1("27183:"); // 27183
    	number = funcexo1("27183/"); // 27183

    	result = funcexo2("28", "14", '+');// == 42
    	result = funcexo2("27", "14", '-');// == 13
    	result = funcexo2("555", "1214", '+');// == 1769
    	result = funcexo2("555", "1214", '-');// == -659


    }
    return 0 ;
}
