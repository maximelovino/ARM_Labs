/*
===============================================================================
 Name        : config_LPC1769.h
 Author      : D. Bechevet, F. Vannel, A. Lescourt
 Copyright   : HES-SO hepia
 Year        : 2013-2014
===============================================================================
*/

#ifndef CONFIG_LPC1769_H_
#define CONFIG_LPC1769_H_


// GPIO
#define	FIO0DIR			(*((volatile uint32_t *) 0x2009C000))
#define	FIO0MASK		(*((volatile uint32_t *) 0x2009C010))
#define	FIO0PIN			(*((volatile uint32_t *) 0x2009C014))
#define	FIO0SET			(*((volatile uint32_t *) 0x2009C018))
#define	FIO0CLR			(*((volatile uint32_t *) 0x2009C01C))

#define	FIO1DIR			(*((volatile uint32_t *) 0x2009C020))
#define	FIO1MASK		(*((volatile uint32_t *) 0x2009C030))
#define	FIO1PIN			(*((volatile uint32_t *) 0x2009C034))
#define	FIO1SET			(*((volatile uint32_t *) 0x2009C038))
#define	FIO1CLR			(*((volatile uint32_t *) 0x2009C03C))

#define	FIO2DIR			(*((volatile uint32_t *) 0x2009C040))
#define	FIO2MASK		(*((volatile uint32_t *) 0x2009C050))
#define	FIO2PIN			(*((volatile uint32_t *) 0x2009C054))
#define	FIO2SET			(*((volatile uint32_t *) 0x2009C058))
#define	FIO2CLR			(*((volatile uint32_t *) 0x2009C05C))

#define	FIO3DIR			(*((volatile uint32_t *) 0x2009C060))
#define	FIO3MASK		(*((volatile uint32_t *) 0x2009C070))
#define	FIO3PIN			(*((volatile uint32_t *) 0x2009C074))
#define	FIO3SET			(*((volatile uint32_t *) 0x2009C078))
#define	FIO3CLR			(*((volatile uint32_t *) 0x2009C07C))

#define	FIO4DIR			(*((volatile uint32_t *) 0x2009C080))
#define	FIO4MASK		(*((volatile uint32_t *) 0x2009C090))
#define	FIO4PIN			(*((volatile uint32_t *) 0x2009C094))
#define	FIO4SET			(*((volatile uint32_t *) 0x2009C098))
#define	FIO4CLR			(*((volatile uint32_t *) 0x2009C09C))
// GPIO Interrupt register map
#define	IO0INTEnR		(*((volatile uint32_t *) 0x40028090))
#define	IO0INTEnF		(*((volatile uint32_t *) 0x40028094))
#define	IO0INTStatR		(*((volatile uint32_t *) 0x40028084))
#define	IO0INTStatF		(*((volatile uint32_t *) 0x40028088))
#define	IO0INTClr		(*((volatile uint32_t *) 0x4002808C))

#define	IO2INTEnR		(*((volatile uint32_t *) 0x400280B0))
#define	IO2INTEnF		(*((volatile uint32_t *) 0x400280B4))
#define	IO2INTStatR		(*((volatile uint32_t *) 0x400280A4))
#define	IO2INTStatF		(*((volatile uint32_t *) 0x400280A8))
#define	IO2INTClr		(*((volatile uint32_t *) 0x400280AC))

#define	IOIntStatus		(*((volatile uint32_t *) 0x40028080))

//TIMER
#define	T0IR			(*((volatile uint32_t *) 0x40004000))
#define	T0TCR			(*((volatile uint32_t *) 0x40004004))
#define	T0TC			(*((volatile uint32_t *) 0x40004008))
#define	T0PR			(*((volatile uint32_t *) 0x4000400C))
#define	T0PC			(*((volatile uint32_t *) 0x40004010))
#define	T0MCR			(*((volatile uint32_t *) 0x40004014))
#define	T0MR0			(*((volatile uint32_t *) 0x40004018))
#define	T0MR1			(*((volatile uint32_t *) 0x4000401C))
#define	T0MR2			(*((volatile uint32_t *) 0x40004020))
#define	T0MR3			(*((volatile uint32_t *) 0x40004024))
#define	T0CCR			(*((volatile uint32_t *) 0x40004028))
#define	T0CR0			(*((volatile uint32_t *) 0x4000402C))
#define	T0CR1			(*((volatile uint32_t *) 0x40004030))
#define	T0EMR			(*((volatile uint32_t *) 0x4000403C))
#define	T0CTCR			(*((volatile uint32_t *) 0x40004070))

#define	T1IR			(*((volatile uint32_t *) 0x40008000))
#define	T1TCR			(*((volatile uint32_t *) 0x40008004))
#define	T1TC			(*((volatile uint32_t *) 0x40008008))
#define	T1PR			(*((volatile uint32_t *) 0x4000800C))
#define	T1PC			(*((volatile uint32_t *) 0x40008010))
#define	T1MCR			(*((volatile uint32_t *) 0x40008014))
#define	T1MR0			(*((volatile uint32_t *) 0x40008018))
#define	T1MR1			(*((volatile uint32_t *) 0x4000801C))
#define	T1MR2			(*((volatile uint32_t *) 0x40008020))
#define	T1MR3			(*((volatile uint32_t *) 0x40008024))
#define	T1CCR			(*((volatile uint32_t *) 0x40008028))
#define	T1CR0			(*((volatile uint32_t *) 0x4000802C))
#define	T1CR1			(*((volatile uint32_t *) 0x40008030))
#define	T1EMR			(*((volatile uint32_t *) 0x4000803C))
#define	T1CTCR			(*((volatile uint32_t *) 0x40008070))

#define	T2IR			(*((volatile uint32_t *) 0x40090000))
#define	T2TCR			(*((volatile uint32_t *) 0x40090004))
#define	T2TC			(*((volatile uint32_t *) 0x40090008))
#define	T2PR			(*((volatile uint32_t *) 0x4009000C))
#define	T2PC			(*((volatile uint32_t *) 0x40090010))
#define	T2MCR			(*((volatile uint32_t *) 0x40090014))
#define	T2MR0			(*((volatile uint32_t *) 0x40090018))
#define	T2MR1			(*((volatile uint32_t *) 0x4009001C))
#define	T2MR2			(*((volatile uint32_t *) 0x40090020))
#define	T2MR3			(*((volatile uint32_t *) 0x40090024))
#define	T2CCR			(*((volatile uint32_t *) 0x40090028))
#define	T2CR0			(*((volatile uint32_t *) 0x4009002C))
#define	T2CR1			(*((volatile uint32_t *) 0x40090030))
#define	T2EMR			(*((volatile uint32_t *) 0x4009003C))
#define	T2CTCR			(*((volatile uint32_t *) 0x40090070))

#define	T3IR			(*((volatile uint32_t *) 0x40094000))
#define	T3TCR			(*((volatile uint32_t *) 0x40094004))
#define	T3TC			(*((volatile uint32_t *) 0x40094008))
#define	T3PR			(*((volatile uint32_t *) 0x4009400C))
#define	T3PC			(*((volatile uint32_t *) 0x40094010))
#define	T3MCR			(*((volatile uint32_t *) 0x40094014))
#define	T3MR0			(*((volatile uint32_t *) 0x40094018))
#define	T3MR1			(*((volatile uint32_t *) 0x4009401C))
#define	T3MR2			(*((volatile uint32_t *) 0x40094020))
#define	T3MR3			(*((volatile uint32_t *) 0x40094024))
#define	T3CCR			(*((volatile uint32_t *) 0x40094028))
#define	T3CR0			(*((volatile uint32_t *) 0x4009402C))
#define	T3CR1			(*((volatile uint32_t *) 0x40094030))
#define	T3EMR			(*((volatile uint32_t *) 0x4009403C))
#define	T3CTCR			(*((volatile uint32_t *) 0x40094070))

//NVIC
#define ISER0			(*((volatile uint32_t *) 0xE000E100))
#define ICER0			(*((volatile uint32_t *) 0xE000E180))
#define ISPR0			(*((volatile uint32_t *) 0xE000E200))
#define ICPR0			(*((volatile uint32_t *) 0xE000E280))
#define IABR0			(*((volatile uint32_t *) 0xE000E300))

#define ISER1			(*((volatile uint32_t *) 0xE000E104))
#define ICER1			(*((volatile uint32_t *) 0xE000E184))
#define ISPR1			(*((volatile uint32_t *) 0xE000E204))
#define ICPR1			(*((volatile uint32_t *) 0xE000E284))
#define IABR1			(*((volatile uint32_t *) 0xE000E304))

#define IPR0			(*((volatile uint32_t *) 0xE000E400))
#define IPR1			(*((volatile uint32_t *) 0xE000E404))
#define IPR2			(*((volatile uint32_t *) 0xE000E408))
#define IPR3			(*((volatile uint32_t *) 0xE000E40C))
#define IPR4			(*((volatile uint32_t *) 0xE000E410))
#define IPR5			(*((volatile uint32_t *) 0xE000E414))
#define IPR6			(*((volatile uint32_t *) 0xE000E418))
#define IPR7			(*((volatile uint32_t *) 0xE000E41C))
#define IPR8			(*((volatile uint32_t *) 0xE000E420))


#endif /* CONFIG_LPC1769_H_ */
