# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 13:29:03 by aabounak          #+#    #+#              #
#    Updated: 2019/12/25 15:13:31 by aabounak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = */*.c

SRCS = srcs/*/*.c

OBJ = *.o

all: $(NAME)
	
$(NAME):
	gcc $(FLAGS) -c $(SRC) -c $(SRCS) -I includes/
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
