/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                  P I T                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "machine/pit.h"
#include "machine/io_port.h"

PIT::PIT (unsigned short us) {
    interval(us);
}

unsigned short PIT::interval () {
    return interv;
}

void PIT::interval(unsigned short us) {
    IO_Port controlp (0x43);
    IO_Port rwport (0x40);
    
    interv = us;

    controlp.outb(0x24);

    rwport.outb(us);

    rwport.outb(us >> 8);
}