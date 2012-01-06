/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            K E Y B O A R D                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "machine/keyctrl.h"
#include "guard/gate.h"
#include "machine/key.h"


class Keyboard : public Keyboard_Controller, public Gate  {
private:
    
    Key key_buffer[1024];
    
    unsigned int length;
    
public:
    
    Keyboard() : Keyboard_Controller(), Gate() {}
    
    void plugin ();
    
    
    virtual bool prologue ();
    
    virtual void epilogue();
    
};

#endif
