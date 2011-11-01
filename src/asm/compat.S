/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              C O M P A T                                  *
 *                                                                           *
 *---------------------------------------------------------------------------*/

/* Define the target section to be code */
.text

/* Define the exported symbols */
.global __pure_virtual, __cxa_pure_virtual, __builtin_delete, _ZdlPv, __cxa_atexit, _alloca, __w32_sharedptr_initialize

/* Implement the symbols as empty functions*/

__pure_virtual:
__cxa_pure_virtual:
__builtin_delete:
_ZdlPv:
__cxa_atexit:
_alloca:
__w32_sharedptr_initialize:
	ret
