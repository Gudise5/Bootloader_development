/*
 * uart.h
 *
 *  Created on: May 17, 2025
 *      Author: gudise
 */

#ifndef UART_H_
#define UART_H_


void uartDebugInit(void);
void uart2_write_char(char ch);
void uart2_write_string(const char *str);


void uart2_init(void);
void uart2_write_char(char ch);
void uart2_write_string(const char *str);


#endif /* UART_H_ */
