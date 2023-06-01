# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asekmani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 17:21:09 by asekmani          #+#    #+#              #
#    Updated: 2022/12/07 08:34:44 by asekmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

SRCS= ft_format.c ft_putchar.c ft_putstr.c ft_putptr.c ft_printf.c ft_putnbr_base.c ft_unsigned_base.c

INC_DIR= ./

OBJS= ${SRCS:.c=.o}

CC= cc

FLAGS= -Wall -Wextra -Werror

RM=rm -f

all: $(NAME)

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

bonus: ${OBJS}
	${AR} ${NAME} ${OBJS}

AR= ar rcs

.c.o:
	${CC} ${FLAGS} -I ${INC_DIR} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all


.PHONY: all clean fclean re bonus
