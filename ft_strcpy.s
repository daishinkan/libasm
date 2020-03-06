section .text
global _ft_strcpy

; delete RDX, RCX, RAX

_ft_strcpy:
			xor rcx, rcx	
			cmp rsi, 0			; !src
			jz done
			jmp copy

copy:
			mov dl, BYTE[rsi + rcx]
			mov BYTE[rdi + rcx], dl
			cmp dl, 0; src[i] != 0
            jz done
			jmp increment       

increment: 
            inc rcx
            jmp copy

done:		mov rax, rdi				; return dst
			ret
