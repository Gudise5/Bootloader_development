/*
 * bsp.c
 *
 *  Created on: May 20, 2025
 *      Author: gudise
 */


#include "stm32f4xx.h"
#include "bsp.h"
#include <stdio.h>
#include <stdbool.h>


#define GPIOAEN		(1U<<0)
#define GPIOCEN		(1U<<2)


#define PIN5		(1U<<5)
#define LED_PIN 	PIN5
#define PIN13		(1U<<13)
#define BUTTON_PIN	PIN13




void led_inti(void)
{
	//enable clock access
	RCC->AHB1ENR |=  GPIOAEN;

	//set PA5 mode to output
	GPIOA->MODER |=(1U<<10);
	GPIOA->MODER &=~(1U<<11);
}

void led_ON(void)
{
	//set PA5 high
	GPIOA->ODR |= LED_PIN;

}

void led_OFF(void)
{
	//set PA5 low
	GPIOA->ODR &=~ LED_PIN;
}

void button_inti(void)
{
	//enable clock access to portC
		RCC->AHB1ENR |=  GPIOCEN;

	//Set PC!3 as an input pin
		GPIOC->MODER |=(1U<<26);
		GPIOC->MODER &=~(1U<<27);

}


bool get_button_state(void)
{

	//Note: Button is active low
	//check if button is pressed or not
	if(GPIOC->IDR & BUTTON_PIN)
	{
		return false;
	}
	else
	{
		return true;
	}
}





































