/*
 * lcd.c
 *
 *  Created on: 27 févr. 2014
 *      Author: fabien
 */

#include "lcd.h"

void init_LCD_GPIO(void)
{
	LCD_CS(1);
	LPC_GPIO0->FIODIR |= 1<<PIN_LCD_CS;
	LPC_GPIO0->FIODIR |= 1<<PIN_LCD_E;
	LPC_GPIO0->FIODIR |= 1<<PIN_LCD_RW;
	LPC_GPIO0->FIODIR |= 1<<PIN_LCD_A0;
}


void Busy()
{
	uint8_t flag=0xff;
	LCD_A0(0);
	LCD_E(1);
	LCD_RW(1);
	while ((flag&0x80)==0x80)
	{
		LCD_E(0);
		asm("nop");
		flag=LCD_DATA_BUS_rd();
		LCD_E(1);
	}
}

void Delay(uint32_t n)
{
	uint32_t a;
	for (a = 0; a < n; a++);
}

void init_LCD(void)
{
	init_LCD_GPIO();
    RESET();
	Delay(1000);
    CLEAR_ADC();	  //Normal disrect (SEG0-SEG128)
    SET_SHL();		// SHL 1,COM33-COM0
    SET_BIAS();   //  1/7 BIAS
    Power_Control(0x07);  //Booster circuit: ON   Voltage regulator circuit: ON  Voltage follower circuit: ON
    Regulor_Resistor_Select(0x05); //V0 voltage regulator internal resistance ratio register value and (1 + Rb/Ra) ratio (Reference value)  5.5
    Set_Contrast_Control_Register(Contrast_level);
	Initial_Dispay_Line(0x00);	//Dispay Line 0
    Write_Instruction(0xF8);	//select booster ratio
	Write_Instruction(0x00);	//4X
	DISPLAY_ON();
}

//Specify DDRAM line for COM0 0~63
void Initial_Dispay_Line(uint8_t line)
{
    line|=0x40;
    Write_Instruction(line);
	return;
}

void Power_Control(uint8_t vol)
{
    Write_Instruction((0x28|vol));
	return;
}

/*  Regulor resistor select
**            1+Rb/Ra  Vo=(1+Rb/Ra)Vev    Vev=(1-(63-a)/162)Vref   2.1v
**            0  3.0       4  5.0(default)
**            1  3.5       5  5.5
**            2  4         6  6
**            3  4.5       7  6.4
*/
void Regulor_Resistor_Select(uint8_t r)
{
    Write_Instruction((0x20|r));
	return;
}

//a(0-63) 32default   Vev=(1-(63-a)/162)Vref   2.1v
void Set_Contrast_Control_Register(uint8_t mod)
{
    Write_Instruction(0x81);
	Write_Instruction(mod);
	return;
}


uint8_t Read_Data(void)
{
	uint8_t data;

	LCD_CS(0);
	//   Busy();
	LCD_A0(1);
	LCD_RW(1);
	LCD_DATA_in();
	LCD_E(1);
	asm("nop");
	LCD_E(0);
	data = LCD_DATA_BUS_rd();
	LCD_CS(1);
	return data;
}


void Write_Data(uint8_t dat)
{
	LCD_CS(0);
	//   Busy();
	LCD_A0(1);
	LCD_RW(0);
	LCD_DATA_BUS_wr(dat);
	LCD_DATA_out();
	LCD_E(1);
	asm("nop");
	LCD_E(0);
	LCD_DATA_in();
	LCD_RW(1);
	LCD_CS(1);
}


void Write_Instruction(uint8_t cmd)
{
	LCD_CS(0);
	//   Busy();
	LCD_A0(0);
	LCD_RW(0);
	LCD_DATA_BUS_wr(cmd);
	LCD_DATA_out();
	LCD_E(1);
	asm("nop");
	LCD_E(0);
	LCD_DATA_in();
	LCD_RW(1);
	LCD_CS(1);
}



void Display_Picture(uint8_t pic[])
{
    uint8_t i,j;
	Initial_Dispay_Line(0x40);
	for(i=0;i<0x04;i++)
	{
	Set_Page_Address(i);
    Set_Column_Address(0x00);
        for(j=0;j<0x80;j++)
		{
		    Write_Data(pic[i*0x80+j]);
		}
	}
    return;
}


void Display_Chess(uint8_t value)
{
    uint8_t i,j,k;
    for(i=0;i<0x04;i++)
	{
		Set_Page_Address(i);

        Set_Column_Address(0x00);

		for(j=0;j<0x40;j++)
		{
		    for(k=0;k<0x01;k++)
		        Write_Data(value);
		    for(k=0;k<0x01;k++)
		        Write_Data(~value);
		}
	}
    return;
}

void Display_read()
{
    uint8_t i,j;
    static uint8_t val[512];
    for(i=0;i<0x04;i++)
	{
		Set_Page_Address(i);

        Set_Column_Address(0x00);

		for(j=0;j<132;j++)
		{
		    val[j+i*132]= Read_Data();

		}
	}
return ;
}

void Display_Picture32(uint32_t pic[])
{
    uint8_t i,j;
	Initial_Dispay_Line(0x40);
	for(i=0;i<0x04;i++)
	{
	Set_Page_Address(i);
    Set_Column_Address(0x00);
        for(j=0;j<0x80;j++)
		{
		    Write_Data((pic[j]>>(i*8))&0xFF );
		}
	}
    return;
}


// Set page address 0~15
void Set_Page_Address(uint8_t add)
{
    add=0xb0|add;
    Write_Instruction(add);
	return;
}

void Set_Column_Address(uint8_t add)
{
    Write_Instruction((0x10|(add>>4)));
	Write_Instruction((0x0f&add));
	return;
}


