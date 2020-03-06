# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekindomb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 12:19:15 by ekindomb          #+#    #+#              #
#    Updated: 2020/02/12 15:19:58 by ekindomb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
global _ft_strlen

; delete RAX
_ft_strlen :
			xor		rax, rax		; i = 0
			jmp		compare

increment : 
			inc		rax				; i++

compare : 
			cmp		BYTE [rdi + rax], 0 ; str[i] == 0 (\0)
			jne		increment

done :	
			ret						; return i 

