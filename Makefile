# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dsaripap <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/27 14:38:43 by dsaripap      #+#    #+#                  #
#    Updated: 2020/02/02 19:14:38 by dsaripap      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_contrast
LIBFT = libft/libft.a
CC = gcc -Wall -Wextra -Werror -g
SRC =	\
		ft_contrast.c \
		ft_saveargs.c \
		ft_readfile.c \
		ft_applycontrast.c \
		ft_listfunctions.c \

OBJ = $(SRC:%.c=%.o)

INCL = libft/includes/

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -o $(NAME) -I./$(INCL) -L./libft -lft $(OBJ)

%.o: %.c $(INCL)
	@$(CC) -o $@ -c $< 

.PHONY: clean

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

lldb: re
	gcc -g main.c -L. -lft

norm:
	norminette $(SRC) $(INCL) | grep -e "Error" -e "Warning" -B 1
