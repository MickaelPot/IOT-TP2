/*
 * uart.h
 *
 *  Created on: Jan 22, 2021
 *      Author: ogruber
 */

#ifndef UART_H_
#define UART_H_

#define NUARTS 3
#define UART0 0
#define UART1 1
#define UART2 2

/*
 * Receives a character, blocking until there is one available
 * The code spins until there is a character available in
 * the UART RX FIFO queue.
 */
void uart_receive(uint8_t uartno, char *pt);

/**
 * Write a ASCII character through the given uart, this is a blocking call.
 * The code spins until there is room in the UART TX FIFO queue to send
 * the character.
 */
void uart_send(uint8_t uartno, char s);

/**
 * This is a wrapper function, provided for simplicity,
 * it sends a C string through the given uart.
 */
void uart_send_string(uint8_t uartno, const char *s);

/*
 * Global initialization for the UARTs
 */
void uarts_init();

/*
 * Enabling the UART.
 * Nothing to do on QEMU until we use interrupts...
 * You can enable or disable the individual interrupts by changing
 */
void uart_enable(uint32_t uartno);

/*
 * Enabling the UART.
 * Nothing to do on QEMU until we use interrupts...
 */
void uart_disable(uint32_t uartno);

#endif /* UART_H_ */
