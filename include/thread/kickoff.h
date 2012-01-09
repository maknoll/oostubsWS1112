#ifndef __kickoff_header__
#define __kickoff_header__

#include "thread/coroutine.h"

/** \brief start a coroutine initially
 *
 * This method is not called directly. It is called throught clever
 * manipulaiton of the stack used by the coroutine. It has to be ensured that
 * this method never returns, since the saved instruction pointer on the stack
 * is bogus.
 *
 * \todo write implementation
 *
 * \param object the coroutine to start
 **/
void kickoff(Coroutine* object);

#endif
