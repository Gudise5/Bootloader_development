/*
 * timebase.c
 *
 *  Created on: May 19, 2025
 *      Author: gudise
 */


#include "stm32f4xx.h"
#include "timebase.h"

#define CTRL_SYS_ENABLE 	(1U<<0)
#define CTRL_SYS_TICKINIT	(1U<<1)
#define CTRL_SYS_CLKSCR		(1U<<2)
#define CTRL_SYS_COUNTFLAG	(1U<<16)


#define ONE_MILE			16000000

volatile uint32_t current_tick = 0;

void timeBase_inti(void)
{
	//disable global interrupts
	__disable_irq();

	//load the timer with number of cycles per second
	SysTick->LOAD = ONE_MILE - 1;

	//clear the current value of sys_tick register
	SysTick->VAL = 0;

	//select internal clock source
	SysTick->CTRL |= CTRL_SYS_CLKSCR;

	//Enable interrupts
	SysTick->CTRL |= CTRL_SYS_TICKINIT;

	//Enable sys_tick
	SysTick->CTRL |= CTRL_SYS_ENABLE;

	//enable global interrupts
	__enable_irq();
}

void SysTick_Handler(void)

{
	if(current_tick > 0 )
	{
		current_tick--;
	}
}

void delay(uint32_t sec)
{

	current_tick = sec;

	while(current_tick != 0)
	{

	}

}


























