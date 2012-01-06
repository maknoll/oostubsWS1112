/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                               L O C K E R                                 *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Locker_include__
#define __Locker_include__

class Locker {
protected:
    
    bool lock;
    
public:
    
    Locker(){
        lock = false;
    }
    
    void enter(){
        lock = true;
    }
    
    void retne(){
        lock = false;
    }
    
    bool avail(){
        return !lock;
    }
};

#endif
