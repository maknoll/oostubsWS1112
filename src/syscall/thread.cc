#include "syscall/thread.h"
#include "syscall/guarded_scheduler.h"

extern Guarded_Scheduler scheduler;

void Thread::resume() {
    scheduler.resume();
}

void Thread::exit() {
    scheduler.exit();
}