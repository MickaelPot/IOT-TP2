/*
 * exception.s
 *
 *  Created on: Jan 24, 2021
 *      Author: ogruber
 */

 /* Standard definitions of Mode bits and Interrupt (I & F) flags in PSRs */

    .equ    CPSR_USR_MODE,       0x10
    .equ    CPSR_FIQ_MODE,       0x11
    .equ    CPSR_IRQ_MODE,       0x12
    .equ    CPSR_SVC_MODE,       0x13
    .equ    CPSR_ABT_MODE,       0x17
    .equ    CPSR_UND_MODE,       0x1B
    .equ    CPSR_SYS_MODE,       0x1F

    .equ    CPSR_IRQ_FLAG,         0x80      /* when set, IRQs are disabled, at the core level */
    .equ    CPSR_FIQ_FLAG,         0x40      /* when set, FIQs are disabled, at the core level */

 /* Exception Vector
  * assume this is linked and loaded at 0x0000-0000
  */
     ldr pc, reset_handler_addr
     ldr pc, undef_handler_addr
     ldr pc, swi_handler_addr
     ldr pc, prefetch_abort_handler_addr
     ldr pc, data_abort_handler_addr
     ldr pc, unused_handler_addr
     ldr pc, irq_handler_addr
     ldr pc, fiq_handler_addr

reset_handler_addr: .word _reset_handler
undef_handler_addr: .word _undef_handler
swi_handler_addr: .word _swi_handler
prefetch_abort_handler_addr: .word _prefetch_abort_handler
data_abort_handler_addr: .word _data_abort_handler
unused_handler_addr: .word _unused_handler
irq_handler_addr: .word _isr_handler
fiq_handler_addr: .word _fiq_handler

_isr_handler:
    b _isr_handler

_unused_handler:
    b _unused_handler // unused interrupt occurred

_fiq_handler:
	b _fiq_handler // unexpected fast interrupt

_undef_handler:
	b _undef_handler // unexpected trap for an undefined instruction

_swi_handler:
	b _swi_handler  // unexpected software interrupt

_prefetch_abort_handler:
	b _panic  // unexpected prefetch-abort trap

_data_abort_handler:
	b _data_abort_handler  // unexpected abort trap

.global _panic
   .func _panic
_panic:
	b _panic
    .size _panic, . - _panic
    .endfunc

