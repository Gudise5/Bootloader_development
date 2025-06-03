
#include "stm32f4xx.h"


#include <stdio.h>
#include <stdbool.h>
#include "bsp.h"
#include "uart.h"
#include "timebase.h"

/*Application 1*/


#define APPLICATION_ADDRESS 0x08008000

int main(void)
{

	led_inti();
	uart2_init();
	timeBase_inti();

	while(1)
	{

		uart2_write_string("hello from application_1\r\n");

		delay(3);

		uart2_write_string("This is Gudise Eshwar\r\n");

		delay(3);
	}

}

void SystemInit(void)
{
	SCB->VTOR = APPLICATION_ADDRESS;
}
