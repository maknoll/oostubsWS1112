/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                               L O C K E R                                 *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Locker_include__
#define __Locker_include__

/** \brief Atomic locking variable
 *
 * Class Locker imlements a locking variable used to secure critical sections of
 * the operating system. It is important to notice that the locking variable 
 * used, only shows if a critical section is occupied or free. Waiting for the
 * locking variable and securing the variable has to implemented otherwise.
 */
class Locker {
protected:
  /** atomar locking variable
   *
   * \todo write declaration
   **/

public:
  /** \brief Default constructor 
   *
   * Initialises the locking variable (free). 
   *
   * \todo write implementation
   **/
  Locker(){

  }

  /** \brief enter a critical section
   *
   * Locks the variable.
   *
   * \todo write implementation
   **/
  void enter(){

  }

  /** \brief return from a critical section
   *
   * Releases locking variable.
   *
   * \todo write implementation
   **/
  void retne(){

  }

  /** \brief test for critical section
   *
   * \todo write implementation
   *
   * @return the value of the locking variable indicating if the critical 
   *         section is occupied or free.
   */
  bool avail(){
	return true;
  }
};

#endif
