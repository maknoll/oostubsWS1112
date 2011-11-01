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
