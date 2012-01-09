/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                          C O R O U T I N E                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/
 
#ifndef __Coroutine_include__
#define __Coroutine_include__

#include "machine/toc.h"

/** \brief Implementation of a context switch concept using coroutines.
 *
 * Every coroutine uses its own stack and every coroutine contains 
 * the structure toc (thread of control) to save the non-volatile registers 
 * before a context switch.
 * The first coroutine is initially activated useing the method go(). Afterwards
 * every context switch is triggered using resume().
 **/
class Coroutine {
private:
  /** \brief saved register content storage 
   *
   *  \todo write declaration
   * **/
    toc savregs;

public:
  /** \brief Default constructor
   * 
   * Initialises the stack, as well as the structure toc containing the 
   * non-volatile registers of this coroutine of the coroutine, using the 
   * external method 'toc_settle()' 
   * 
   * @param tos pointer to the stack used by this coroutine
   */
  Coroutine(void* tos);

  /** \brief triggers a context switch
   *
   * This method delegates to the scheduler
   *
   * \todo write implementation
   **/
  void resume();

  /** \brief exit this coroutine
   *
   * This method delegates to the scheduler
   *
   * \todo write implementation
   **/
  void exit();

  /** \brief real function of the coroutine,
   *
   * since every coroutine does something differenct this method has to be
   * implemented by a subclass of Coroutine (e.g. Application).
   **/
  virtual void action() = 0;

  /* friend declaration so that, Dispatcher can access the register content storage */
  friend class Dispatcher;
};

#endif
