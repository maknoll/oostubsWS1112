/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            K E Y B O A R D                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "machine/keyctrl.h"
#include "guard/gate.h"
#include "machine/key.h"
 
/** \brief %Keyboard driver with interrupt support
 *
 * This class is a subclass of Gate and implements the interrupt routine used 
 * for the keyboard.
 */
class Keyboard : public Keyboard_Controller, public Gate  {
   
public:
   
  /** \brief enable the interrupt mechanism of the keyboard
   *
   * \todo write implementation
   *
   * Method plugin() enables all keyboard interrupts. After calling plugin()
   * interrupts activated by the keyboard are recognised.
   */
  void plugin ();

  /** \brief handle keyboard interrupt
   *
   *  \todo write implementation
   *
   * **/
  
  virtual void trigger ();
};

#endif
