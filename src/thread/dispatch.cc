/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                          D I S P A T C H E R                              *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "thread/dispatch.h"

Dispatcher::Dispatcher() {
    current_active = 0;
}

void Dispatcher::go(Entrant& first) {
    if(!current_active) {
        current_active = &first;
        toc_go(&(first.savregs));
    }
}

void Dispatcher::dispatch(Entrant& next) {
    Entrant *running = current_active;
    current_active = &next;
    toc_switch(&(running->savregs),&(next.savregs));
}

Entrant* Dispatcher::active() const {
    return current_active;
}