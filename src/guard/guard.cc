/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                G U A R D                                  *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "guard/guard.h"
#include "object/queue.h"
#include "machine/cpu.h"

extern CPU cpu;

Gate* Guard::remove_epilogue() {
    cpu.disable_int();
    Gate* g = (Gate*) queue.dequeue();
    cpu.enable_int();
    
    return g;
}

void Guard::leave() {
    Gate* item = remove_epilogue();
    
    while (item != 0) {
        item->queued(false);
        cpu.enable_int();
        item->epilogue();
        cpu.disable_int();
        
        item = remove_epilogue();
    }
    
    retne();
}

void Guard::relay(Gate* item) {
    cpu.disable_int();
    
    if (!item->queued()) {
        queue.enqueue(item);
        item->queued(true);
    }
    
    cpu.enable_int();
    
    if (avail()) {
        enter();
        leave();
    }
}