# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dsaripap <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/27 14:38:43 by dsaripap      #+#    #+#                  #
#    Updated: 2019/05/15 17:41:41 by dsaripap      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

PROG = prog
NAME = libft.a
CC = gcc -Wall -Wextra -Werror -g

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m # No Color

SRC = ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstaddend.c \
	  ft_strarrtolst.c \
	  ft_lstlen.c \
	  ft_lstfindelem.c \
	  ft_lstsort.c \
	  ft_del.c \
	  ft_strreplace.c \
	  get_next_line.c

OBJ = $(SRC:%.c=%.o)

INCL = includes/

all: $(NAME)

$(NAME): $(OBJ)
	@echo "${GREEN}Making libft.a${NC}"
	@ar crs $(NAME) $(OBJ)

%.o: %.c $(INCL)
	@$(CC) -c $<

.PHONY: clean

clean:
	@echo "${RED}Cleaning all object files of libft${NC}"
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test:
	@$(CC) main.c -L. -lft -o test.exe

lldb: re
	@gcc -g main.c -L. -lft

$(PROG): $(NAME)
	$(CC) -o $(PROG) main.c -L. -lft

norm:
	norminette $(SRC) $(INCL) | grep -e "Error" -e "Warning" -B 1
