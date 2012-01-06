/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            K E Y B O A R D                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "device/keyboard.h"
#include "machine/io_port.h"
#include "device/cgastr.h"
#include "machine/pic.h"
#include "machine/plugbox.h"

extern CGA_Stream kout;
extern PIC pic;
extern Plugbox plugbox;

void Keyboard::plugin () {
    length = 0;
    
    plugbox.assign(Plugbox::keyboard, *this);
	pic.allow(PIC::keyboard);
}

bool Keyboard::prologue () {
    Key k = key_hit();
    
    if(k.valid()){
        if (k.alt() && k.ctrl() && k.scancode()==83) {
            reboot();
        } else {
            if (length != 1023) {
                key_buffer[length++] = k;
            }
        }
	}
	
	return k.valid();
}

void Keyboard::epilogue() {
    
    unsigned short x,y;
//    kout.drop();
    kout.getpos(x,y);
    kout.setpos(39,10);
    kout << "$ ";
    while (length > 0)
        kout << key_buffer[--length].ascii();
    kout.flush();
    kout.setpos(x,y);
}
