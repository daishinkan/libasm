section .text 
global _ft_strcmp

; delete rax

_ft_strcmp:
			xor rax, rax
			cmp rdi, 0x0	; !s1 
			jz null_check
			cmp rsi, 0x0	; !s2 
			jz null_check
			jmp check

null_check:
			cmp rdi, rsi	; s1==s2(NULL)
			jz equal
			jg superior
			jmp inferior

check:		
			cmp BYTE[rdi + rax], 0x0 ; s1[i] != 0
			je last_char
			cmp BYTE[rsi + rax], 0x0 ; s2[i] != 0
			je last_char
			jmp compare

compare:	
			movzx rdx, BYTE[rdi + rax]
            movzx rcx, BYTE[rsi + rax]
            cmp rdx, 0
            jz last_char
            cmp rcx, 0
            jz last_char
			cmp rcx, rdx
			jne last_char

increment:	inc rax
            jmp compare

last_char:
			movzx rdx, BYTE[rdi + rax]
            movzx rcx, BYTE[rsi + rax]
			sub rdx, rcx
			cmp rdx, 0
			je equal
			jl inferior
			jg superior

equal:		mov rax, 0
			ret 

inferior:	mov rax, -1
			ret 
superior:	mov rax, 1
			ret 
