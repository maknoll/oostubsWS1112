/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                          D I S P A T C H E R                              *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __dispatch_include__
#define __dispatch_include__

#include "thread/entrant.h"

/** \brief Thread/Coroutine of control switch instance.
 *
 * Starts and switches between threads/coroutines.
 */
class Dispatcher {
private:
  /** \brief Pointer to the currently active coroutine 
   *
   * \todo write declaration
   * **/
    Entrant* current_active;

public:
  /** \brief Default constructor.
   *
   * \todo write implementation
   *
   *  Initializes current thread/coroutine to be invalid, since system is not
   *  yet started.
   **/
  Dispatcher();

  /** \brief starts the execution of the first coroutine of the 
   * operating system.
   *
   * \todo write implementation
   *
   * @param first reference of the coroutine that will be executed first.
   */
  void go(Entrant& first);

  /** \brief  switche the thread of control to the specified 
   * coroutine. 
   *
   * This method can be called by a coroutine or through the scheduler.
   *
   * \todo write implementation
   *
   * @param next reference of the coroutine that will be executed next.
   */
  void dispatch(Entrant& next);

  /** \brief returns the currently active coroutine.
   *
   * \todo write implementation
   * 
   * @return pointer for the currently active coroutine.
   */
  Entrant* active() const;
};

#endif
