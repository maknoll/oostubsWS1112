/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                G U A R D                                  *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Guard_include__
#define __Guard_include__

#include "guard/locker.h"
#include "guard/gate.h"
#include "object/queue.h"


class Guard : public Locker {
    
    Queue queue;
    
	Gate* remove_epilogue();
    
public:
    
	void leave();
    
	void relay(Gate* item);
};

#endif
