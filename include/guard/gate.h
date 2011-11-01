/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                  G A T E                                  *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Gate_include__
#define __Gate_include__

/** \brief Interrupt handling base class
 *
 * Superclass of a set of classes that are able to handle interrupts. Every
 * subclass of Gate has to implement method trigger() with appropriated
 * behavior.
 **/
class Gate {
  
public:
  /** \brief interrupt handling method
   *
   * This method is called after an interrupt occured. It is executed 
   * asynchronous to other activities of the operation system. To enable 
   * different behavior according to the occured interrupt this method has to 
   * be implemented in a subclasses of Gate.
   **/
	virtual void trigger() = 0;
};

#endif
