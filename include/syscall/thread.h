/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                             T H R E A D                                   *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __thread_include__
#define __thread_include__

#include "thread/entrant.h"

/** \brief Threads are preemptible multitasking entities
 *
 * Every %Thread contain exactly one line of execution, due to their preemptiveness all operations concerning them must be called Secure
 *
**/
class Thread : public Entrant{
public:
  /** \brief Default constructor
   *
   * Delegates initialization to the underlying Entrant object
   *
   * \param tos pointer to the stack used by this thread
   */
  Thread(void* tos) : Entrant(tos){}

   /** \brief triggers a context switch
   *
   * This method delegates to the Guarded_Scheduler
   *
   * \todo write implementation
   **/
  void resume();

  /** \brief exit this coroutine
   *
   * This method delegates to the Guarded_Scheduler
   *
   * \todo write implementation
   **/
  void exit();

  /** \brief real function of the %Thread,
   *
   * since every thread does something differenct this method has to be
   * implemented by a subclass of Thread (e.g. Application).
   **/
  virtual void action() = 0;   
};

#endif
