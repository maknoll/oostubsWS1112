/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                 P A N I C                                 *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __panic_include__
#define __panic_include__

#include "guard/gate.h"


class Panic  : public Gate {
public:
    
    
    virtual bool prologue ();
    
    virtual void epilogue();
};

#endif
