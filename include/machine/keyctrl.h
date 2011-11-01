/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                       K E Y B O A R D _ C O N T R O L L E R               *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Keyboard_Controller_include__
#define __Keyboard_Controller_include__

#include "machine/io_port.h"
#include "machine/key.h"

class Keyboard_Controller {
private:
    
    unsigned char code;
    
    unsigned char prefix;
    
    Key gather;
    
    char leds;
    
    const IO_Port ctrl_port;
    
    const IO_Port data_port;
    
    enum StatusMasks{ 
        outb = 0x01,
        inpb = 0x02,
        auxb = 0x20
    };
    
    enum Commands{
        cmd_set_led = 0xed,
        cmd_set_speed = 0xf3,
        cmd_cpu_reset = 0xfe
    };
    
    enum Responses{ 
        ack = 0xfa
    };
    
    enum Decodes{ 
        break_bit = 0x80, 
        prefix1 = 0xe0, 
        prefix2   = 0xe1
    };
    
public:
    
    enum Leds{ 
		caps_lock = 4, 
		num_lock = 2, 
		scroll_lock = 1
	};
    
private:
    
    static unsigned char normal_tab[];
    
    static unsigned char shift_tab[];
    
    static unsigned char alt_tab[];
    
    static unsigned char asc_num_tab[];
    
    static unsigned char scan_num_tab[];
    
    bool key_decoded ();
    
    void get_ascii_code ();
    
public:
    
    Keyboard_Controller ();
    
    Key getKeyFromScanCode (unsigned char scanCode);
    
    Key key_hit ();
    
    void reboot ();
    
    void set_repeat_rate (unsigned char speed, unsigned char delay);
    
    void set_led (Leds led, bool on);
};

#endif
