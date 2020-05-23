/* Xinu for STM32
 *
 * Original license applies
 * Modifications for STM32 by Robin Krens
 * Please see LICENSE and AUTHORS 
 * 
 * $LOG$
 * 2019/11/11 - ROBIN KRENS
 * Initial version 
 * 
 * $DESCRIPTION$
 *
 * */

/* platinit.c - platinit */

#include <xinu.h>

//RAFA
#include <serial_avr.h>


void uartinit();


/*------------------------------------------------------------------------
 * platinit - platform specific initialization
 *------------------------------------------------------------------------
 */

// RAFA puso lo siguiente
// extern int _edata;
// extern int __data_start;
// extern int _etext;

void platinit(void)
{
	/* Load .data segment into SRAM */
	// extern uint32 * etext, data, edata;
	// int size = (&edata - &data); 
	// memcpy(&data, &etext, size);	

	/* Initialize UART Serial communication */
	// RAFA uartinit();
	// serial_init();
	// serial_put_char('A');
	// serial_put_char('B');
	// serial_put_str("Xinu AVR loading...\n");
	
	/* Initialize the Interrupt Controller (evec.c) */
	initintc();

	/* System calls */
	syscall_init();
}

/* Simple UART initialization, not using a TTY device
Used by kprintf and early system debugging */

void uartinit()
{
	
	// STM32 specific: struct	uart_csreg *uptr;	/* Address of UART's CSRs */
	// STM32 specific: struct 	gpio_csreg *gptr;	
	// STM32 specific: struct 	clock_csreg *cptr;

	/* Enable 'clock' on peripherals */
	// STM32 specific: cptr = (struct clock_csreg *)CLOCK_BASE;
	// STM32 specific: cptr->apb2enr |= (1 << IOPAEN) | (1 << USART1EN);

	/* Set in and output mode (dirty) */
	// STM32 specific: gptr = (struct gpio_csreg *)(0x40010800);
	// STM32 specific: gptr->crh = 0x44444894;

	/* Enable peripheral */
	// STM32 specific: uptr = (struct uart_csreg *)(0x40013800);
	// STM32 specific: uptr->cr1 &= ~(1 << UART_EN);
	
	/* Set baudrate 115200 */
	// STM32 specific: uptr->brr = 0x00000045;
	
	// STM32 specific: uptr->cr1 |= (1 << UART_INTR_RX) | (1 << UART_TX_EN) | (1 << UART_RX_EN);
	// STM32 specific: uptr->cr1 |= (1 << UART_EN);
	
}
