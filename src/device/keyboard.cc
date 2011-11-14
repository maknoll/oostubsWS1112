/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            K E Y B O A R D                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

/* INCLUDES */
#include "device/keyboard.h"
#include "machine/io_port.h"
#include "device/cgastr.h"
#include "machine/pic.h"
#include "machine/plugbox.h"

/* GLOBAL VARIABLS */
extern CGA_Stream kout;
extern PIC pic;
extern Plugbox plugbox;

/* METHODS */
void Keyboard::plugin () {
    
    plugbox.assign(Plugbox::keyboard, *this);
	pic.allow(PIC::keyboard);
}

void Keyboard::trigger () {
    Key k = key_hit();
    
    if (k.valid()) {
        if (k.alt() && k.ctrl() && k.scancode()==83) {
            reboot();
        } else {
            unsigned short x,y;
            kout.getpos(x,y);
            kout.setpos(39,10);
			kout << "$ " << k.ascii();
			kout.flush();
            kout.setpos(x,y);
        }
	}
}