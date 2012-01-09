#define ASM 1
#include "machine/toc.h"

/* This file is a gnu assembler file, therefore AT&T Syntax is needed*/

.global toc_go, toc_switch

toc_go:
    mov 4(%esp), %ecx
    mov 0(%ecx), %ebx
    mov 4(%ecx), %esi
    mov 8(%ecx), %edi
    mov 12(%ecx), %ebp
    mov 16(%ecx), %esp
    ret

toc_switch:
    mov 4(%esp), %ecx
    mov %ebx, 0(%ecx)
    mov %esi, 4(%ecx)
    mov %edi, 8(%ecx)
    mov %ebp, 12(%ecx)
    mov %esp, 16(%ecx)

    mov 8(%esp), %ecx
    mov 0(%ecx), %ebx
    mov 4(%ecx), %esi
    mov 8(%ecx), %edi
    mov 12(%ecx), %ebp
    mov 16(%ecx), %esp
    ret

