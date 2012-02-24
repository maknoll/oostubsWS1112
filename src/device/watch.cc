/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              W A T C H                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "device/watch.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "syscall/guarded_scheduler.h"

extern PIC pic;
extern Plugbox plugbox;
extern Guarded_Scheduler scheduler;

void Watch::windup() {
    plugbox.assign(Plugbox::timer, *this);
    pic.allow(PIC::timer);
}

bool Watch::prologue() {
    return true;
}

void Watch::epilogue() {
    scheduler.resume();
}