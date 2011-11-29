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
 * used as default for interrupts.
 */
class Panic  : public Gate {
public:
  
  /** handle unknown interrupt and halt system
   *
   * \todo write implementation
   *
   * \return always false, due to stopping of system
   **/
  virtual bool prologue ();

   /** never called due to stopping of system
	*
	* \todo write implementation
   **/
  virtual void epilogue();
};

#endif
