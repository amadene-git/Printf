# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: admadene <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/16 13:56:44 by admadene          #+#    #+#              #
#    Updated: 2019/10/13 18:45:50 by admadene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	fonction_init.c\
				format_d.c\
		        format_p.c\
				format_s.c\
				format_x.c\
				ft_abs.c\
				ft_calloc.c\
				ft_isdigit.c\
				ft_llutoxa.c\
				ft_printf_utils.c\
				ft_printf_utils_2.c\
				ft_strdup.c\
				ft_strrev.c\
				ft_utoxa.c\
				format_c.c\
				format_d_utils.c\
				format_percent.c\
				format_u.c\
				format_x_maj.c\
				ft_bzero.c\
				ft_isalpha.c\
				ft_itoa.c\
				ft_printf.c\
				ft_putstr.c\
				ft_strlen.c\
				ft_utoa.c\
				ft_utoxa_maj.c

OBJS		= ${SRCS:.c=.o }

CFLAGS		= -Wall -Wextra -Werror

CC		= gcc

RM		= rm -f

NAME		= libftprintf.a

HEADER		= ft_printf.h

.c.o 	:
			${CC} ${CFLAGS} -I  ${HEADER}  -c $< -o ${<:.c=.o}


all	:	${NAME}

$(NAME)	: 	${OBJS}
			ar rc ${NAME} ${OBJS}

clean	:
			${RM} ${wildcard *.o}

fclean	:	clean
			${RM} ${NAME}

re	:	fclean all

.PHONY	:	all clean fclean re

