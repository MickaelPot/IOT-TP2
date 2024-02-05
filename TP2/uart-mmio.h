/*
 * uart.h
 *
 *  Created on: Jan 22, 2021
 *      Author: ogruber
 */

#ifndef UART_MMIO_H_
#define UART_MMIO_H_

/**
 * To fill this header file,
 * look at the document describing the Versatile Application Board:
 *
 *    Versatile Application Baseboard for ARM926EJ-S (DUI0225)
 */

/*
 * We need the base address for the different serial lines.
 */

#define UART0_BASE_ADDRESS ((void*)0x101F1000) // ???
#define UART1_BASE_ADDRESS ((void*)0x101F2000) // ???
#define UART2_BASE_ADDRESS ((void*)0x101F3000) // ???

/*
 * Is the UART chipset a PL011?
 * If so, we need the details for the data and status registers.
 */
#define UART_DR 0x00 // ???
#define UART_FR 0x18 // ???

#endif /* UART_MMIO_H_ */
