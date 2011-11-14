/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                  P I C                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "machine/pic.h"
#include "machine/io_port.h"

PIC::PIC(){

	IO_Port ctrl_1(0x20), ctrl_2(0xa0), mask_1(0x21), mask_2(0xa1);

	ctrl_1.outb(0x11);
	ctrl_2.outb(0x11);

	mask_1.outb(32);
	mask_2.outb(40);

	mask_1.outb(4);
	mask_2.outb(2);

	mask_1.outb(3);
	mask_2.outb(3);

	mask_1.outb(0xFB);
	mask_2.outb(0xFF);
}

void PIC::allow(Interrupts interrupt) {
    IO_Port mask_1(0x21), mask_2(0xa1);
    
    unsigned char ocw1;
    
    if (0 <= interrupt && interrupt < 8){
        ocw1 = mask_1.inb();
		ocw1 &= ~(1 << interrupt);
		mask_1.outb(ocw1);
	} else if (8 <= interrupt && interrupt < 16){
	    ocw1 = mask_2.inb();
		ocw1 &= ~(1 << (interrupt-8));
		mask_2.outb(ocw1);
	}
}

void PIC::forbid(Interrupts interrupt) {
    IO_Port mask_1(0x21), mask_2(0xa1);
    
    unsigned char ocw1;
    
    if (0 <= interrupt && interrupt < 8){
        ocw1 = mask_1.inb();
		ocw1 |= (1 << interrupt);
		mask_1.outb(ocw1);
	} else if (8 <= interrupt && interrupt < 16){
	    ocw1 = mask_2.inb();
		ocw1 |= (1 << (interrupt-8));
		mask_2.outb(ocw1);
	}
}

void PIC::ack() {
    IO_Port ctrl_1(0x20), ctrl_2(0xa0);
    
    ctrl_1.outb(0x20);
    ctrl_2.outb(0x20);
}
