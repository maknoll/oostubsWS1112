/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                               S E C U R E                                 *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Secure_include__
#define __Secure_include__

#include "guard/guard.h"

extern Guard guard;

class Secure {
public:
    
    inline Secure(){
        guard.enter();
    }
    
    inline ~Secure(){
        guard.leave();
    }
};

#endif
