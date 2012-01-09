/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            E N T R A N T                                  *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __entrant_include__
#define __entrant_include__

#include "thread/coroutine.h"
#include "object/chain.h"

/** \brief Schedulable %Coroutine
 *
 *  This class extends the coroutine by the needed functionality to put them in
 *  list, so the scheduler can handle them.
 *
 **/
class Entrant : public Chain, public Coroutine{
public:
  /** \brief Default constructor
   *
   * \param tos pointer to the stack used by this coroutine
   **/
  Entrant(void* tos) : Coroutine(tos){}
};

#endif
