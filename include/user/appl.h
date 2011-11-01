/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                         A P P L I C A T I O N                             *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __application_include__
#define __application_include__

/** \brief Basis of OOStuBs-Applications
 *
 * This class defines the only application used by oo-StuBS. Every application
 * class is derived from this class.
 */        
class Application {
public:
                    
  /** \brief Start the application
   *
   * This method must be overwritten by the derived class.
   */
  virtual void action ()=0;
};

#endif
