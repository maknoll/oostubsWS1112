/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              M U L T I B O O T                            *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __multiboot_header__
#define __multiboot_header__

/* MACROS */

/** \brief Magic number to identify multiboot header. **/
#define MULTIBOOT_HEADER_MAGIC          0x1BADB002

#ifdef __ELF__
/** \brief Flag definition for ELF executables. */
# define MULTIBOOT_HEADER_FLAGS         0x00000003
#else
/** \brief Flag definition for a.out executables. **/
# define MULTIBOOT_HEADER_FLAGS         0x00010003
#endif

/** \brief Magic number passed by a Multiboot-compliant boot loader. **/
#define MULTIBOOT_BOOTLOADER_MAGIC      0x2BADB002

/* Do not include in assembly files */
#ifndef ASM

/* INCLUDES */

#include <stdint.h>

/* TYPES */

struct Multiboot_Info;

#endif /* ! ASM */
#endif /* ! __multiboot_header__ */
