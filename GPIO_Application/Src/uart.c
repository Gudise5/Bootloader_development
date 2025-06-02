/*
 * uart.c
 *
 *  Created on: May 17, 2025
 *      Author: gudise
 */

#include "stm32f4xx.h"
#include "uart.h"

#define GPIOAEN				(1U<<0)
#define UART2ENABLE			(1U<<17)
#define UART2BDRATE			(115200)
#define STSTEMCLOCK			16000000
#define AHB1CLOCK			STSTEMCLOCK
#define USARTCR1TE			(1U<<3)
#define USARTCR1UE 			(1U<<13)
#define USARTSRTXE			(1U<<7)


/*
static uint16_t calculateUART_bd(uint16_t peripharalClock, uint16_t baudrate);
static void configureUART2_baudrate(uint16_t peripharalClock, uint16_t baudrate);
static void UART_trasmit(int ch);
*/

/*

int __io_putchar(int ch)
{
	UART_trasmit(ch);
	return ch;

}

void uartDebugInit(void)
{
	//GPIO configure
	//enable clock access to gpioA
	RCC->AHB1ENR |= (1U<<0);

	//set as AF
	GPIOA->MODER &=~ (1U<<4);
	GPIOA->MODER |=  (1U<<5);

	//set AF for UART as uart_TX
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &=~ (1U<<11);


	//UART configure
	//enable clock access for UART
	RCC->APB1ENR |= UART2ENABLE;

	//set baud rate
	configureUART2_baudrate(AHB1CLOCK,UART2BDRATE);

	//Enable Transmit and Receive transfer direction
	USART2->CR1 |= USARTCR1TE ;

	//enable module
	USART2->CR1 |= USARTCR1UE;

}

static uint16_t calculateUART_bd(uint16_t peripharalClock, uint16_t baudrate)
{
	return ((peripharalClock +(baudrate/2U))/baudrate);

}

static void configureUART2_baudrate(uint16_t peripharalClock, uint16_t baudrate)
{
	USART2->BRR = calculateUART_bd(peripharalClock, baudrate);
}

static void UART_trasmit(int ch)
{
	//transmit register should me empty
	while (!(USART2->SR & USARTSRTXE)){}
	//store data in transmit register
	USART2->DR = (ch & 0XFF);
}
*/


void uart2_init(void) {
    // Enable clocks
	    // 1. Enable clocks
	    RCC->AHB1ENR |= GPIOAEN;
	    RCC->APB1ENR |= UART2ENABLE;

	    // 2. Configure PA2 as USART2_TX
	    GPIOA->MODER &= ~(0x3 << (2 * 2));
	    GPIOA->MODER |=  (0x2 << (2 * 2));

	    GPIOA->AFR[0] &= ~(0xF << (4 * 2));
	    GPIOA->AFR[0] |=  (0x7 << (4 * 2));

	    GPIOA->OSPEEDR |= (0x3 << (2 * 2));
	    GPIOA->PUPDR &= ~(0x3 << (2 * 2));

	    // 3. Setup USART2
	    USART2->BRR = 16000000 / 115200;   // For 16MHz clock
	    USART2->CR1 |= USARTCR1TE;
	    USART2->CR1 |= USARTCR1UE;

}

void uart2_write_char(char ch) {
    while (!(USART2->SR& USARTSRTXE));
    USART2->DR = ch;
}

void uart2_write_string(const char *str) {
    while (*str) uart2_write_char(*str++);
}
































