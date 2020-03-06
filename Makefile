# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekindomb <ekindomb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 13:01:35 by ekindomb          #+#    #+#              #
#    Updated: 2020/02/24 14:26:34 by ekindomb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libasm.a
SRCS= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
SRCS_BONUS= ft_list_size.s
OBJS=${SRCS:.s=.o}
OBJS_BONUS=${SRCS_BONUS:.s=.o}
NASM = nasm -f macho64
FLAGS = -Wall -Werror -Wextra
cc = clang
TEST = test

all : ${NAME}

${NAME} : ${OBJS}
		@ar rc ${NAME} ${OBJS}
		@ranlib ${NAME}

%.o  : %.s
	@${NASM} $<

test: ${NAME}
	@echo " .____     .__ ___.                              "
	@echo " |    |    |__|\_ |__  _____     ______  _____   "
	@echo " |    |    |  | | __ \ \__  \   /  ___/ /     \  "
	@echo " |    |___ |  | | \_\ \ / __ \_ \___ \ |  Y Y  \ "
	@echo " |_______ \|__| |___  /(____  //____  >|__|_|  / "
	@${cc} ${FLAGS} -L. -lasm main.c -o $(TEST)
   
re: fclean all

fclean: clean
		@rm -rf ${NAME} $(TEST)

clean : 
		@rm -rf ${OBJS}

.PHONY:	all fclean clean re test
