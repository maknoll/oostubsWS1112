/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                 T O C                                     *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "machine/toc.h"

void toc_settle (struct toc* regs, void* tos, void (*kickoff)(void*), void* object) {
    regs->ebx = 0;
    regs->esi = 0;
    regs->edi = 0;
    regs->ebp = (tos-2*sizeof(void*));
    regs->esp = (tos-3*sizeof(void*));
    *((void* *)tos-3) = (void*)kickoff;
    *((void* *)tos-1) = object;
}