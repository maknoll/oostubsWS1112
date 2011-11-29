/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                               S E C U R E                                 *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Secure_include__
#define __Secure_include__

/** \brief RAII implemented critical section
 *
 * Class Secure is used as a simple interface to set and release the 
 * lockvariable we used for securing critical sections of the operating system. 
 * The constructor locks and the destructor releases the variable, so simply 
 * declaring the object is enough to secure the scope of the object.
 */
class Secure {
public:
  /** \brief Default constructor enters critical section
   *
   * Sets the lock through method guard.enter().
   *
   * \todo write implementation
   **/
  Secure(){

  }

  /** \brief Default destructor leaving critical section
   * 
   * Unsets the lock through method guard.leave().
   *
   * \todo write implementation
   **/
  ~Secure(){

  }
};

#endif
