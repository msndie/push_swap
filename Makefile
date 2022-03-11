# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 20:32:12 by sclam             #+#    #+#              #
#    Updated: 2022/01/28 17:30:20 by sclam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P	= 	push_swap

NAME_C	=	checker

CFLAGS	=	-Wall -Wextra -Werror

SRCS_C	=	srcs/checker.c \
			srcs/push.c \
			srcs/swap.c \
			srcs/sort.c \
			srcs/exit.c \
			srcs/rotate.c \
			srcs/sort_big.c \
			srcs/rev_rotate.c \
			srcs/struct_args.c \
			srcs/list_operations.c \
			srcs/numb_operations.c

SRCS_P	=	srcs/main.c \
			srcs/push.c \
			srcs/swap.c \
			srcs/sort.c \
			srcs/exit.c \
			srcs/rotate.c \
			srcs/sort_big.c \
			srcs/rev_rotate.c \
			srcs/struct_args.c \
			srcs/list_operations.c \
			srcs/numb_operations.c

LIBFT	=	/libft/libft.a

CC		= 	cc

OBJS_P	=	${SRCS_P:.c=.o}

OBJS_C	=	${SRCS_C:.c=.o}

RM		= 	rm -f

HEAD	= 	includes/push_swap.h

%.o : %.c	${HEAD}
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEAD}

all:		${NAME_P} ${NAME_C}

${NAME_P}:	${OBJS_P} ${HEAD}
			@make -C ./libft
			${CC} ${CFLAGS} ${OBJS} ${OBJS_P} -o ${NAME_P} -L./libft -lft

${NAME_C}:	${OBJS_C} ${HEAD}
			${CC} ${CFLAGS} ${OBJS} ${OBJS_C} -o ${NAME_C} -L./libft -lft

clean:
			${RM} ${OBJS_C} ${OBJS_P}
			make clean -C ./libft

fclean:		clean
			${RM} ${NAME_P}
			${RM} ${NAME_C}
			make fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re