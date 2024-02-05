/*
 * uart.c
 *
 *  Created on: Jan 22, 2021
 *      Author: ogruber
 */
#include "main.h"
#include "uart.h"
#include "uart-mmio.h"

struct uart {
  uint8_t uartno;
  void* bar;
};

static
struct uart uarts[NUARTS];

static
void uart_init(uint32_t uartno, void* bar) {
  struct uart*uart = &uarts[uartno];
  uart->uartno = uartno;
  uart->bar = bar;
  // no hardware initialization necessary
  // when running on QEMU
}

void uarts_init() {
  uart_init(UART0,UART0_BASE_ADDRESS);
  uart_init(UART1,UART1_BASE_ADDRESS);
  uart_init(UART2,UART2_BASE_ADDRESS);
}

void uart_enable(uint32_t uartno) {
  struct uart*uart = &uarts[uartno];
}

void uart_disable(uint32_t uartno) {
  struct uart*uart = &uarts[uartno];
}

void uart_receive(uint8_t uartno, char *pt) {
  struct uart*uart = &uarts[uartno];
  // TODO: not implemented yet...
  while ((mmio_read32(uart->bar, UART_FR) & 10000)) //On doit analyser le bit 4 (RXFE) qui indique si la FIFO de reception est 0. S il il est a 1 alors la FIFO de reception se remplie
  {
    
  }
  uint32_t valeur_ascii_character= mmio_read32(uart->bar, UART_DR);
  
  
  //panic();
}

/**
 * Sends a character through the given uart, this is a blocking call
 * until the character has been sent.
 */
void uart_send(uint8_t uartno, char s) {
  struct uart* uart = &uarts[uartno];
  // TODO: not implemented yet...
  panic();
}

/**
 * This is a wrapper function, provided for simplicity,
 * it sends a C string through the given uart.
 */
void uart_send_string(uint8_t uartno, const char *s) {
  while (*s != '\0') {
    uart_send(uartno, *s);
    s++;
  }
}

