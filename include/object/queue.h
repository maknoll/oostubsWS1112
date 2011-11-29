/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              Q U E U E                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __queue_include__
#define __queue_include__

#include "object/chain.h"

/** \brief Simple linked list of %Chain objects.
 * 
 * Unlike other implementations of linked lists tail is not pointing to the last
 * item of the list but to the next pointer of the last item or as long as the
 * list is empty to the head of the list. This saves the verification for 
 * existing items if an item is queued. If however an item is removed this 
 * verification has to be done.
 */
class Queue {
protected:
  /** \brief pointer to first element of the queue **/
  Chain* head;

  /** \brief pointer to the pointer of the last list element
   *
   *  if the list is empty this points to head
   **/
  Chain** tail;

public:
  /** Default constructor
    *
	* Intializes tghe queue to be empty, sets head to NULL and tail to point to head
   **/
  Queue () { head = 0; tail = &head; }

  /** \brief insert item to the end of the list
   *
   * \param item pointer to chain element to be inserted
   **/
  void enqueue (Chain* item);

  /** \brief remove item from the front of the list
   *
   * \return pointer to the removed element, or NULL if empty
   **/
  Chain* dequeue ();

  /** \brief remove an item from the list
   *
   * \param item pointer to the item, that should be removed
   **/
  void remove (Chain* item);
};

#endif
