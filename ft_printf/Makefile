# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 13:16:04 by togomes-          #+#    #+#              #
#    Updated: 2025/03/24 18:06:39 by togomes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

SRCS =  ft_printf.c ft_print_hexa.c ft_print_pointer.c ft_print_unsigned.c\
		ft_print_functions.c

OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
