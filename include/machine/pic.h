/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                  P I C                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __pic_include__
#define __pic_include__

#include "machine/io_port.h"

/** \brief Driver for Programmable Interrupt Controller
 *
 * The PIC or Programmable Interrupt Controller enables the system to 
 * allow/forbid interrupts. By allowing an interrupt the PIC defines which
 * interrupts are handled by the system. It is important that interrupts will
 * only be handled if the interrupt has been allowed and if the handling of 
 * interrupts is enabled (see class CPU). 
 */
class PIC {
public:
	/** \brief External interrupt sources **/
	enum Interrupts
	{
		keyboard = 1	/**< Keyboard controller **/
	};

   /** \brief Default Constructor
	*
	* Setting up the PIC and masking all incoming interrupt channels
	**/
   PIC();

  /** \brief allow a specific hardware interrupt
   *
   * \todo write implementation
   *
   * Enables the system to handle interrupts of the specified 
   * device using the PIC. To enable the handling of any interrupt 
   * CPU::enable_int() has to be called first.
   *
   * \param interrupt number of interrupt that will be allowed
   */
   void allow(Interrupts interrupt);

  /** \brief forbid a specific hardware interrupt
   *
   * \todo write implementation
   *
   * Disables an interrupt useing the PIC.
   *
   * \param interrupt number of interrupt that will be forbiden
   */
   void forbid(Interrupts interrupt); 

  /** \brief acknowledge the handling of a pending interrupt
   *
   *  \todo write implementation
   *
   * Acknowledge an occured interrupt. This tells the PIC that his last
   * interrupt has been handled. This Method has to be called before the cpu is
   * allowed to handle any new interrupts. If an interrupt is not acknowledged
   * the same interrupt is called again and again.
   */
   void ack();
};

#endif
