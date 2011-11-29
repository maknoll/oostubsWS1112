/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              C H A I N                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __chain_include__
#define __chain_include__

/** \brief Single linked list element
 *
 * Chain implements the pointer enableing us to insert an object into a simple 
 * linked list.
 */
class Chain {
public:
  /** \brief pointer to next element in the queue **/
  Chain* next;
};

#endif
