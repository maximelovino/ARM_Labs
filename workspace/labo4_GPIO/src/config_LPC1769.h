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



#endif /* CONFIG_LPC1769_H_ */
