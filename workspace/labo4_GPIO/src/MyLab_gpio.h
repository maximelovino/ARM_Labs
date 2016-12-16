/*
 * MyLab_gpio.h
 *
 *  Created on: 1 déc. 2016
 *      Author: lovinom
 */

#ifndef MYLAB_GPIO_H_
#define MYLAB_GPIO_H_

void Led8SetState (uint8_t value);

void init(void);

void delai(uint16_t delai);

void LedSetState (uint8_t led, bool state);

bool JoystickGetState (uint8_t pos);

uint8_t SwitchGetState (void);

#endif /* MYLAB_GPIO_H_ */
