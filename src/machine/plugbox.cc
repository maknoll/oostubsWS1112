/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              P L U G B O X                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

/* INCLUDES */
#include "machine/plugbox.h"
#include "device/panic.h"
#include "device/cgastr.h"

/* GLOBALE VARIABLES */
extern CGA_Stream kout;

Panic panic;

/* METHODEN */
Plugbox::Plugbox () {
    
    for (int i = 0; i < 256; i++) {
        assign (i, panic);
    }
}

void Plugbox::assign(unsigned short slot, Gate& gate) {
    gates[slot] = &gate;
}

Gate& Plugbox::report(unsigned short slot) {
    return *(gates[slot]);
}

