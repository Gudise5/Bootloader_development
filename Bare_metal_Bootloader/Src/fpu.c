/*
 * fpu.c
 *
 *  Created on: May 17, 2025
 *      Author: gudise
 */

#include "stm32f4xx.h"
#include "fpu.h"



void fpu_enable(void )
{

	//In Co-processor Access Control Register enable Enable CP10 and CP11

	SCB->CPACR |= (0xF << 20);
}
