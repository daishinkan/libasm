section .text
global _ft_write

; delete rax
_ft_write:
            xor rax, rax
            mov rax, 0x02000004
            syscall
            jc trash        ; all error return value, i'll return -1
            ret

trash :
            mov rax, -1
            ret
