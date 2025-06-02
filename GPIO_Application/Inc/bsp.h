/*
 * bsp.h
 *
 *  Created on: May 20, 2025
 *      Author: gudise
 */

#ifndef BSP_H_
#define BSP_H_

#include <stdbool.h>


void led_inti(void);
void led_ON(void);
void led_OFF(void);

void button_inti(void);
bool get_button_state(void);





#endif /* BSP_H_ */
