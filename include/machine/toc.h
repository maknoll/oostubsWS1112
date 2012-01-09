/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                 T O C                                     *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __toc_include__
#define __toc_include__

/* To access elements of the toc structure using an assembler method, the
 * offsets of the elements are needed. To ease programming the offsets are hard
 * coded here and can be used within assembler code.
 */

#define EBX_OFFSET 0
#define ESI_OFFSET 4
#define EDI_OFFSET 8
#define EBP_OFFSET 12
#define ESP_OFFSET 16

/* Don't include in assembler files */
#ifndef ASM

/** \brief Thread of control register structure
 *
 * The structure %toc or better 'thread of control' is used to save the values
 * of the non-volatile registers if a context switch occurs. EAX, ECX and EDX
 * are volatile registers if the GNU C compiler is used. Their values are not
 * guaranteed to remain the same after a function call and can therefore be
 * changed without saving and restoring them.
 **/ 
  struct toc {
	  /** \brief copy of ebx content **/
	  void *ebx;
	  
	  /** \brief copy of esi content **/
	  void *esi;

	  /** \brief copy of edi content **/
	  void *edi;
	  
	  /** \brief copy of ebp content **/
	  void *ebp;

	  /** \brief copy of esp content **/
	  void *esp;
 };

#ifdef __cplusplus
extern "C"{
#endif /* C++ */

/**\brief initialise toc and stack of newly created thread
 *
 * To do this it creates the stack in a way, that after
 * setting the esp to the current top of stack of this coroutine, the saved
 * instruction pointer points to the supplied kickoff function.
 * Also the actual toc saved esp points to the supplied top of stack
 *
 * \todo write implementation
 *
 * \param regs pointer to the structur toc of the thread
 * \param tos pointer to the top of stack of the thread
 * \param kickoff pointer to method kickoff()
 * \param object pointer to the thread that will be initialiesed
 */
void toc_settle (struct toc* regs, void* tos, void (*kickoff)(void*), void* object);

/** \brief start first thread
 *
 * This function is used to start the first thread/coroutine in the system, it is
 * similar to toc_switch, but it does not need to save the current registers.
 *
 * \todo write implementation
 *
 * \param regs the toc of the first thread
 **/
void toc_go(struct toc* regs) __attribute__((noinline));

/** \brief switch to next thread
 *
 * This function switches threads/coroutines by switching the current register
 * content of the cpu with the content of the saved registers of the next
 * thread, also the current cpu registers must be saved to the toc structure of
 * the current thread/coroutine
 *
 * \todo write implementation
 *
 * \param next the toc of the next thread
 * \param current storage to save current toc into
 **/
void toc_switch(struct toc* current, struct toc* next) __attribute__((noinline));

#ifdef __cplusplus
}
#endif /* C++ */

#endif /* Assembler */

#endif /* GUARD */
