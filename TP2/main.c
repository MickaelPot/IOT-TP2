#include "main.h"
#include "uart.h"


extern void _panic();
void panic() {
  _panic();
}

extern uint32_t irq_stack_top;
extern uint32_t stack_top;

void check_stacks() {
  void *memsize = (void*)MEMORY;
  void *addr;
  addr = &stack_top;
  if (addr >= memsize)
    panic();
  addr = &irq_stack_top;
  if (addr >= memsize)
    panic();
}

/**
 * This is the C entry point,
 * upcalled once the hardware has been setup properly
 * in assembly language, see the startup.s file.
 */
void _start(void) {
  char c;
  check_stacks();
  uarts_init();
  uart_enable(UART0);
  for (;;) {
    uart_receive(UART0, &c);
    uart_send(UART0, c);
  }
}
