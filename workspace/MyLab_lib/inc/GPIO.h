/*
 * GPIO.h
 *
 *  Created on: 1 déc. 2016
 *      Author: lovinom
 */
#ifndef GPIO_H_
#define GPIO_H_

#include "config_LPC1769.h"
#include <stdint.h>
#include <stdbool.h>

void Led8SetState (uint8_t value);

bool fallingEdgeJoystick (uint8_t pos);

void init(void);

void delai(uint16_t delai);

void LedSetState (uint8_t led, bool state);

bool JoystickGetState (uint8_t pos);

uint8_t SwitchGetState (void);

#endif /* GPIO_H_ */
