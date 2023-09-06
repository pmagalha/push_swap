# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 11:38:42 by pmagalha          #+#    #+#              #
#    Updated: 2023/09/06 10:47:58 by pmagalha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

NAME = push_swap

SRC = lists_aux.c main.c \
vibe_check.c sorting.c radix.c simple_sort.c \
index.c operations.c

OBJ = $(SRC:.c=.o)

LIBFT = libs/libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libs/libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean: 
	$(MAKE) clean -C ./libs/libft
	@$(RM) $(OBJ) $(OBJ_BNS)

fclean : clean
	@$(RM) $(LIBFT) $(NAME)

re: fclean all	