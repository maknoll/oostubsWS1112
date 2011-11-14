/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              G U A R D I A N                              *
 *                                                                           *
 *---------------------------------------------------------------------------*/

/* INCLUDES */
#include "machine/pic.h"
#include "machine/plugbox.h"
#include "device/cgastr.h"

extern PIC pic;
extern Plugbox plugbox;
extern CGA_Stream kout;

/* METHODS  */
extern "C" void guardian (unsigned short slot);

/** \brief Entry point for interrupts
 *
 * @param slot number of occurred interrupt
 */
void guardian (unsigned short slot) {
    
    if (slot < 256) {
        
        Gate *g = &plugbox.report(slot);
        
        g->trigger();
        
        pic.ack();
    }
}
