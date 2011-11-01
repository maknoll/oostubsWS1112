/* Tell includes, that this is an assembly file */
#define ASM 1
#include <machine/multiboot.h>
#include <config.h>


.text					/* The fallowing is code */

	
.globl  entry	/* Define the entry point for the bootloader to be exported */


.macro	wrapperGen			/* Assembler macro to create interrupt wrapper  */
	.ifeq \@				/* \@ is an automatically incremented variable, */
		INT_WRAPPER_START:	/* it is incremented, everytime the macro		*/
	.endif					/* is expanded. 								*/

	int_wrapper_\@:
	push %eax
	mov	$\@, %al
	jmp	callGuardian
	
	.ifeq \@
		INT_WRAPPER_END:
	.endif
.endm

.align  4					/* The Multiboot header must be aligned to 32bit */
     
multiboot_header:
    .long   MULTIBOOT_HEADER_MAGIC
    .long   MULTIBOOT_HEADER_FLAGS
    .long   -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
#ifndef __ELF__
    .long   multiboot_header
    .long   _start
    .long   _edata
    .long   _end
    .long   entry
#endif
     
entry:						/* Entry point of the system */
	 cli

gdtSetup:					/* Initialize the GDT */
	 lgdt GDTR				/* Load the static GDT */

	 mov 	$0x10, %cx		/* Setting the segment selectors*/
	 mov	%cx, %ss		/* stack is data*/
	 mov	%cx, %ds		
	 mov	%cx, %es
	 mov	%cx, %gs
	 mov	%cx, %fs

stackSetup:					/*Creating a stack*/
	 mov	$(stack + BOOT_STACK_SIZE), %esp
	
multibootSetup:				/* Passing multiboot arguments to kernel */
	 pushl	%ebx			
	 pushl	%eax

idtSetup:
	mov	$initialIDT, %eax	/* Load the base address of the IDT template */
	mov	$255, %dl			/* There are 255 interrupts */
	movl	$(int_wrapper_0-INT_WRAPPER_END+INT_WRAPPER_START), %ebx	/* Load base address of the wrapper function */

.loop:
	add    $(INT_WRAPPER_END-INT_WRAPPER_START), %ebx					/* Load the address of the current wrapper function */
	movl   %ebx, %ecx
	mov	%cx, 	 (%eax)													/* Copy the lower bytes of the address to the IDT */
	shr	$16, %ecx
	mov	%cx,	6(%eax)													/* Copy the upper bytes of the address to the IDT */
	add	$8,	%eax
	dec	%dl
	jnz	.loop

	lidt IDTR															/* Load the IDT */

disableNMI:					/* Disable non-maskable interrupts */
	mov	$0x80, %al			/* NMI verbieten */
	out	%al, $0x70

setupObj:					/* Call the constructors of global objects */
	call _init

callKernel:					/* Call the C/C++ main function of the operating system */
	call kernel

destroyObj:					/* Call the destructors of global objects */
	call _fini

leaveKernel:				/* The operating system ended, halt the CPU */
	cli
.halt:	hlt
		jmp .halt



intWrappers:				/* Create the interrupt wrappers */
	.rept 256
		wrapperGen
	.endr

callGuardian:				/* Unified interrupt handling routine */

	cld						/* expected by gcc */

	push %ecx				/* save volatile registers */
	push %edx

	andw $0xFF, %ax 		/* the interrupt wrapper only provides 8bit */
	push %ax				/* push the argument of the C/C++ interrupt handler */

	call guardian			/* call the interrupt handler */

	pop %ax					/* cleanup */

	pop %edx				/* retrieve saved registers */
	pop %ecx
	pop %eax

	iret					/* leave interrupt */




.bss						/* the fallowing is uninitialized reserved memory */

	.comm   stack, BOOT_STACK_SIZE 	/* memory for stack */





.data						/* pre-initialized memory */

GDTR:						/* The gdt pseudo-register */
	.short	3*8				/* 3 segments, null, code, data */
	.int	initialGDT		/* start of GDT */

IDTR:						/* The idt pseudo-register */
	.short 256*8			/* 256 handlers */
	.int   initialIDT		/* start if IDT */

	.align 4

initialGDT:					/* The fixed GDT for the operating system */

nullSegment:				/* Null segment as expected by x86 architecture */
	.short	0
	.short	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0

codeSegment:				/* Code segment, flat memory model, read and execute */
	.short	0xFFFF
	.short	0
	.byte	0
	.byte	0x9A
	.byte	0xCF
	.byte	0

dataSegment:				/* Data segment, flat memory model, read and write */
	.short	0xFFFF
	.short	0
	.byte	0
	.byte	0x92
	.byte	0xCF
	.byte	0


initialIDT:					/* The fixed IDT for the initial protected mode setup */

traps:						/* 32 Trap handler for CPU generated traps */
	.rept	32
		.short	0
		.short  0x8
		.byte	0
		.byte	0xEF
		.short	0
	.endr

externalInts:				/* 224 interrupt handler for possibly external interrupts */
	.rept	224
		.short	0
		.short  0x8
		.byte	0
		.byte	0xEE
		.short	0
	.endr
