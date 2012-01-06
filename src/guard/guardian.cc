/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              G U A R D I A N                              *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "machine/pic.h"
#include "machine/plugbox.h"
#include "device/cgastr.h"
#include "guard/guard.h"
#include "machine/cpu.h"

extern PIC pic;
extern Plugbox plugbox;
extern CGA_Stream kout;
extern Guard guard;
extern CPU cpu;


extern "C" void guardian (unsigned short slot);



void guardian (unsigned short slot) {
    if (slot < 256) {
        Gate *g = &plugbox.report(slot);
        
        if (g->prologue()) {
            guard.relay(g);
        }
        
        pic.ack();
    }
}

/*
void guardian (unsigned short slot) {
    
    if (slot < 256) {
        
        Gate *g = &plugbox.report(slot);
        
        g->trigger();
        
        pic.ack();
    }
}
*/