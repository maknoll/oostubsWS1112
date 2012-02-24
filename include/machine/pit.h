/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                  P I T                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __pit_include__
#define __pit_include__

/** \brief Programmable Interval Timer driver
 *
 * This driver provides discrete time interval notifications needed to
 * implement clocks and timer.
 **/
class PIT { 
    unsigned short interv;
public:
  /** \brief Default Constructor
   * 
   * Initialising the PIT with a specific configurations containing timer interval and mode of operation.
   *
   * \todo write implementation
   *
   * \param us timer intervall in microseconds
   **/
  PIT (unsigned short us);
  
  /** \brief get the current timer intervall
   *
   * \todo write implementation
   *
   * \return the current timer interval of the PIT.
   */
  unsigned short interval ();
  
  /** \brief reprogram the PIT with a new timer interval
   * 
   * \todo write implementation
   *
   * \param us the new timer interval
   */
  void interval(unsigned short us); 
};

#endif
