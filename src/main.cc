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
#include "user/task1.h"

/* GLOBAL OBJECTS */

/** \todo define global objects **/

CGA_Stream kout;
Keyboard_Controller keyboard; 

/* METHODS  */

extern "C" void kernel(uint32_t magic, const Multiboot_Info* addr);

/** \brief kernel entry point
 *
 * This is the entry point of the operating system.  If this function returns
 * all interrupts will be disabled and the cpu will be halted.
 *
 * \todo uncomment Task1
 *
 * \param magic bootloader magic value
 * \param addr address of multiboot info structure
 **/

void kernel(uint32_t magic, const Multiboot_Info* addr){

Task1 task(magic, addr);

task.action();

}
