/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                   G U A R D E D _ S C H E D U L E R                       *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __guarded_scheduler_include__
#define __guarded_scheduler_include__

#include "syscall/thread.h"
#include "thread/scheduler.h"

/** \brief Scheduler guarded by Secure
 *
 * This Scheduler is interrupt safe and therefore needed to cope with
 * preemptive switching of Threads.  Since now the multitasking is preemptiv
 * Threads instead of Coroutines are handled.
 **/
class Guarded_Scheduler : public Scheduler{
public:
  /** \brief Start the scheduling by starting the first thread
   *
   * If there is one contained in the queue of the scheduler.
   *
   * \todo write implementation
   **/ 
  void schedule();
  
  /** \brief Insert the specified thread into the ready queue
   *
   * \todo write implementation
   *
   * \param that reference to the thread to be inserted
   **/
  void ready(Thread& that);

  /** \brief Remove the currently active thread from the queue
   *
   * If there are no more threads, wait for new threads to arive.
   *
   * \todo write implementation
   **/
  void exit();

  /** \brief Remove the specified thread from the queue of processes.
   *
   * If the supplied entry is equal to the currently active coroutine, call exit().
   *
   * \todo write implementation
   *
   * \param that reference of the thread to be killed.
   */
  void kill(Thread* that);

  /** \brief Use the scheduling algorithm to get the next thread and
   * resume with that thread.
   *
   * \todo write implementation
   **/
  void resume();
};

#endif
