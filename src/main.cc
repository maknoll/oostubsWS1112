/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              M A I N                                      *
 *                                                                           *
 *---------------------------------------------------------------------------*/

/* INCLUDES */

#include "machine/multiboot.h"
#include "device/cgastr.h"
#include "machine/keyctrl.h"
#include "machine/pic.h"
#include "machine/cpu.h"
#include "machine/plugbox.h"
#include "device/keyboard.h"
#include "guard/guard.h"
#include "user/task4.h"
#include "thread/scheduler.h"

/* GLOBAL OBJECTS */

/** \todo define global objects **/

CGA_Stream kout;
PIC pic;
CPU cpu;
Plugbox plugbox;
Keyboard keyboard;
Guard guard;
Scheduler scheduler;

/* METHODS  */

extern "C" void kernel(uint32_t magic, const Multiboot_Info* addr);

/** \brief kernel entry point
 *
 * This is the entry point of the operating system.  If this function returns
 * all interrupts will be disabled and the cpu will be halted.
 *
 * \todo uncomment Task4
 *
 * \param magic bootloader magic value
 * \param addr address of multiboot info structure
 **/

void kernel(uint32_t magic, const Multiboot_Info* addr){

    kout.clear();
    
    keyboard.plugin();
    
    Task4 task;
    
    //scheduler.ready(task);
    
    task.action();
  
    scheduler.schedule();

}
