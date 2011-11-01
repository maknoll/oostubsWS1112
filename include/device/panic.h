/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                 P A N I C                                 *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __panic_include__
#define __panic_include__

/* INCLUDES */
#include "guard/gate.h"

/** \brief Default interrupt handler
 *
 * This class is a subclass of Gate and implements a standard interrupt routine
 * used as default for unknown/registered interrupts.
 */
class Panic  : public Gate {
public:
  
  /** \brief handle unknown/unregistered interrupt 
   *
   *  \todo write implementation
   *
   * For debug purposes the cpu will be halted if an unknown interrupt occurs.
   **/
  virtual void trigger();

};

#endif
