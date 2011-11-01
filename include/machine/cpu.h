/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                   C P U                                   *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __CPU_include__
#define __CPU_include__

/** \brief Hardware accessor for %CPU specific instructions
 *
 * Class CPU implements an abstraction of the processor. It provides methods to
 * enable/disable interrupts globally and to halt the processor.
 */
class CPU {
public:
  /** \brief globally enable interrupts **/
  inline void enable_int () {
    asm("sti");
  }

  /** \brief globally dissable interrupts **/
  inline void disable_int () {
    asm("cli");
  }

  /** \brief halt the cpu
   *
   * When the cpu is halted the program counter will not increase until an
   * interrupt occurs.  If an interrupt occurs the cpu will handle the
   * interrupt and continue with the execution after the halt command.
   */
  inline void halt () {
    asm("hlt");
  }
};

#endif
