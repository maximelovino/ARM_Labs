/*
 * lcd.h
 *
 *  Created on: 27 févr. 2014
 *      Author: fabien
 */

#ifndef LCD_H_
#define LCD_H_

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#define PIN_LCD_CS	0
#define PIN_LCD_E	1
#define PIN_LCD_RW	22
#define PIN_LCD_A0	24

#define DISPLAY_ON()           Write_Instruction(0xaf)   //  Display on
#define DISPLAY_OFF()          Write_Instruction(0xae)   //  Display off
#define SET_ADC()              Write_Instruction(0xa1)   //  Reverse disrect (SEG128-SEG0)
#define CLEAR_ADC()            Write_Instruction(0xa0)   //  Normal disrect (SEG0-SEG128)
#define REVERSE_DISPLAY_ON()   Write_Instruction(0xa7)   //  Reverse display : 0 illuminated
#define REVERSE_DISPLAY_OFF()  Write_Instruction(0xa6)   //  Normal display : 1 illuminated
#define ENTIRE_DISPLAY_ON()    Write_Instruction(0xa5)   //  Entire dislay   Force whole LCD point
#define ENTIRE_DISPLAY_OFF()   Write_Instruction(0xa4)   //  Normal display
#define SET_BIAS()             Write_Instruction(0xa3)   //  bias 1   1/7 bias
#define CLEAR_BIAS()           Write_Instruction(0xa2)   //  bias 0   1/9 bias
#define SET_MODIFY_READ()      Write_Instruction(0xe0)   //  Stop automatic increment of the column address by the read instruction
#define RESET_MODIFY_READ()    Write_Instruction(0xee)   //  Cancel Modify_read, column address return to its initial value just before the Set Modify Read instruction is started
#define RESET()                Write_Instruction(0xe2)
#define SET_SHL()              Write_Instruction(0xc8)   // SHL 1,COM33-COM0
#define CLEAR_SHL()            Write_Instruction(0xc0)   // SHL 0,COM0-COM33

static inline void LCD_CS(uint8_t val) {if (val) LPC_GPIO0->FIOSET=1<<PIN_LCD_CS; else LPC_GPIO0->FIOCLR=1<<PIN_LCD_CS;}
static inline void LCD_E(uint8_t val)  {if (val) LPC_GPIO0->FIOSET=1<<PIN_LCD_E;  else LPC_GPIO0->FIOCLR=1<<PIN_LCD_E;}
static inline void LCD_RW(uint8_t val) {if (val) LPC_GPIO0->FIOSET=1<<PIN_LCD_RW; else LPC_GPIO0->FIOCLR=1<<PIN_LCD_RW;}
static inline void LCD_A0(uint8_t val) {if (val) LPC_GPIO0->FIOSET=1<<PIN_LCD_A0; else LPC_GPIO0->FIOCLR=1<<PIN_LCD_A0;}
static inline void LCD_DATA_in(void)  {	LPC_GPIO2->FIODIR &= ~0xFF;}
static inline void LCD_DATA_out(void) {	LPC_GPIO2->FIODIR |= 0xFF; }
static inline uint32_t LCD_DATA_BUS_rd(void) {return (LPC_GPIO2->FIOPIN)&0xFF;}
static inline void LCD_DATA_BUS_wr(uint8_t val) {LPC_GPIO2->FIOPIN0=val;}


void init_LCD_GPIO(void);


// private function
void Busy(void);
void Delay(uint32_t n);
void init_LCD(void);
void Initial_Dispay_Line(uint8_t line);
void Power_Control(uint8_t vol);
void Regulor_Resistor_Select(uint8_t r);
void Set_Contrast_Control_Register(uint8_t mod);
void Write_Data(uint8_t dat);
void Write_Instruction(uint8_t cmd);


void Display_Chess(uint8_t value);
void Set_Page_Address(uint8_t add);
void Set_Column_Address(uint8_t add);

void Display_Picture32(uint32_t pic[]);

static uint8_t Contrast_level=19;




#endif /* LCD_H_ */
