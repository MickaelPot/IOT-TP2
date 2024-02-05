
/*
 * Define the different sections included in the ELF file.
 */
SECTIONS
{
  . = 0x0;
  . : { build/exception.o(.text) }
  
  . = 0x1000; 
  .text : { 
     build/startup.o(.text)
     build/*(.text) 
  }
  . = ALIGN(4); 
  .data : { build/*(.data) }
  /*
   * Include the data sections that must be zeroed upon starting up.
   * Align the section on a 4byte boundary, it is cleaner and more
   * efficient for an ARM processor. Especially that we do not enable
   * unaligned accesses in memory by the ARM processor.
   * Look at the startup code to see how memory is reset to zero
   * between _bss_start and _bss_end
   * NOTA BENE: 
   *   we zero 16 bytes at a time (look at the code in startup.s
   *   so we align this section on 16-byte boundaries, both the start
   *   and end.
   */ 
  . = ALIGN(4); 
 .bss . : {
   _bss_start = .;
   build/*(.bss COMMON)
   . = ALIGN(16); 
   _bss_end = .;
 } 
 /* 
  * Finally, reserve some memory for the C stack
  * Remember that stacks are growing downward, 
  * so the top of the stack is at the end of 
  * the reserved memory region. 
  * NOTA BENE: 
  *    there are no runtime checks to check that 
  *    your stack does not overflow at runtime when
  *    nesting too many C function calls. 
  */
 . = ALIGN(8);
 . = . + 0x1000; /* 4KB of stack memory */
 stack_top = .;
 
 . = ALIGN(8);
 . = . + 0x1000; /* 4KB of stack memory */
 irq_stack_top = .;
 
}
