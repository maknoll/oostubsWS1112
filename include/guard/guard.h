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

/** \brief Interrupt synchronisation handler
 *
 * Guard enables the operating system to synchroniste actions of interrupt 
 * handlers for critical sections that are secured using the lock of the 
 * Guard object.
 */
class Guard : public Locker {
  /** \brief queue of waiting epilogues 
   *
   * \todo write declaration
   **/

  /** \brief remove a queued epilogue from the queue
   *
   * This method has to be called secured to ensure that the structure of the
   * queue stays consistent.
   *
   * \todo write implementation
   *
   * @return a pointer to the Gate object implementing the next epilogue, or
   * NULL if queue is empty.
   */
	Gate* remove_epilogue();

public:
  /** \brief leave the critical section
   *
   * Waiting epilogues can be processed now.
   *
   * \todo write implementation
   **/ 
	void leave();

  /** \brief try to execute epilogue
   *
   * If possible the epilogue is processed right away but if the critical
   * section used for the epilogue is locke the epilogue has to be queued for
   * later processing.
   *
   * \todo write implementation
   *
   * @param item pointer to the Gate object implementing the epilogue.
   **/
	void relay(Gate* item);
};

#endif
