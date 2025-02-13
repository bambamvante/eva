# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 21:42:27 by arphueng          #+#    #+#              #
#    Updated: 2024/12/29 03:16:41 by arphueng         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../get_next_line.a
SRCS = get_next_line.c get_next_line_utils.c 
SRCS_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f
OBJ = $(SRCS:%.c=%.o)
OBJ_BONUS = $(SRCS_BONUS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ) 
	ar -rcs $(NAME) $(OBJ) 

bonus: $(OBJ) $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ) $(OBJ_BONUS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY : all clean fclean re bonus
