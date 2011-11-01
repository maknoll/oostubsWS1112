/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              P L U G B O X                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Plugbox_include__
#define __Plugbox_include__

#include "guard/gate.h"

/** \brief Interrupt forwarding administration unit
 *
 * This Class is  an abstraction of the IDT (interrupt descriptor table). It
 * enables the system to define an appropriate handling routine for every hard
 * and software interrupt.
 **/
class Plugbox {
private:
  /** \brief array of pointers to Gate objects
   *
   * \todo write declaration
   **/

public:
   
  /** \brief Default constructor
   *
   * \todo write implementation
   *
   * initialising the map with Panic Gates. 
   **/
  Plugbox ();

  /** \brief assign a Gate object to a specific interrupt
   *
   * \todo write implementation
   *
   * \param slot number of interrupt the gate object will be assigned to
   * \param gate reference of the gate object containing the handling routine 
   *             for the interrupt
   */
   void assign(unsigned short slot, Gate& gate) ;

  /** \brief report the assigned Gate object for a specific interrupt
   *
   * \todo write implementation
   *
   * \param slot number of occured interrupt 
   * \return reference of the Gate object or the Panic gate, if none was assigned
   */
  Gate& report(unsigned short slot);
};

#endif
