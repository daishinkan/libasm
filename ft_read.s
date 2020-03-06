section .text 
global _ft_read

_ft_read :
            mov rax, 0x2000003
            syscall
            jc trash        ; all error, return -1
            ret 
trash:
            mov rax, -1
            ret
