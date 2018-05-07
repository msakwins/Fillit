# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 12:54:10 by ocojeda-          #+#    #+#              #
#    Updated: 2016/12/26 19:19:24 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRCS = srcs/display.c srcs/parse.c srcs/solve.c srcs/solveutils.c \
srcs/checking1.c srcs/checking2.c srcs/backtrack.c 
LIBRARIES = libft/libft.a fillit.a
OBJECTS = display.o parse.o solve.o solveutils.o checking1.o checking2.o backtrack.o

all: $(NAME)

$(NAME):
	@make -C ./libft
	@gcc -c $(FLAGS) $(SRCS)
	@ar rc fillit.a $(OBJECTS)
	@ranlib fillit.a
	@gcc $(FLAGS) ./srcs/main.c $(LIBRARIES) -o $(NAME)
clean:
	@rm -f $(OBJECTS) fillit.a main.o
	@make clean -C ./libft
fclean:	clean
	@rm -f $(NAME)
	@make fclean -C ./libft
re: fclean all
