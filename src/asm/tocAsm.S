#define ASM 1
#include "machine/toc.h"

/* This file is a gnu assembler file, therefore AT&T Syntax is needed*/

.global toc_go, toc_switch

toc_go:
    mov 4(%esp), %ecx
    mov EBX_OFFSET(%ecx), %ebx
    mov ESI_OFFSET(%ecx), %esi
    mov EDI_OFFSET(%ecx), %edi
    mov EBP_OFFSET(%ecx), %ebp
    mov ESP_OFFSET(%ecx), %esp
    ret

toc_switch:
    mov 4(%esp), %ecx
    mov %ebx, EBX_OFFSET(%ecx)
    mov %esi, ESI_OFFSET(%ecx)
    mov %edi, EDI_OFFSET(%ecx)
    mov %ebp, EBP_OFFSET(%ecx)
    mov %esp, ESP_OFFSET(%ecx)

    mov 8(%esp), %ecx
    mov EBX_OFFSET(%ecx), %ebx
    mov ESI_OFFSET(%ecx), %esi
    mov EDI_OFFSET(%ecx), %edi
    mov EBP_OFFSET(%ecx), %ebp
    mov ESP_OFFSET(%ecx), %esp
    ret

