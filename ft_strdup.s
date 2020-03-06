section .text
global _ft_strdup
extern _malloc

_ft_strdup:                     ; rdi = str
            xor rcx, rcx
            cmp rdi, 0      ; !str
            jz null_return
            jmp malloc_len     ; ft_strlen(str) or len(rdi)

malloc_end: 
            inc rcx
            jmp malloc_len

malloc_len: mov dl, BYTE[rdi + rcx]
            cmp dl, 0       ; str[i] != 0
            jne malloc_end

malloc_start: 
            inc rcx
            push rdi        ; save the stack
            mov rdi, rcx   ; give malloc size of str
            call _malloc   ; call function malloc
            pop rdi        ; ret the rdi value
            cmp rax, 0      ; allocation fail
            jz trash
            xor rcx, rcx
copy:
            mov dl, BYTE[rdi + rcx]
            mov BYTE[rax + rcx], dl
            cmp dl, 0
            jz return 
            jmp increment
increment:
            inc rcx
            jmp copy

return:     ret

trash:      xor rax, rax
            ret

null_return: xor rax, rax 
