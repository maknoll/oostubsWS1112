/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              W A T C H                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __watch_include__
#define __watch_include__

/* INCLUDES */
#include "guard/gate.h"
#include "machine/pit.h"

/** \brief Interrupt handling class for PIT interrupts
 *
 * This class implements the interrupt handler for PIT interrupts, therefore it
 * is a timer with a specific task.  In OOStuBs the class is used to execute
 * the preemptible switch of Threads
 **/
class Watch : public Gate, public PIT {
public:
  /** \brief Default Constructor
   *
   * Initailises the PIT with supplied value
   *
   * \todo write implementation
   *
   * \param us preemtible Thread execution time in microseconds
   **/
  Watch (unsigned int us) : PIT (us) {}

  /** \brief register the watch with the plugbox and enable hardware interrupt
   *
   * \todo write implementation
   */
  void windup();

  /** \brief prologue of the timer interrupt
   *
   * does nothing
   *
   * \todo write implementation
   *
   * \return always true
   **/
  virtual bool prologue();

  /** \brief epilogue implementing the thread switch
   *
   * \todo write implementation
   **/
  virtual void epilogue();
};

#endif
