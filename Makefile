FILES = main.c \
		parser.c \
		placer.c \
		tab_filler.c \
		get_next_line.c

SRC_DIR = src
SRC = $(FILES:%=$(SRC_DIR)/%)

NAME = njaber.filler

OBJ_DIR = obj
OBJ = $(FILES:%.c=$(OBJ_DIR)/%.o)

CFLAGS= -Llibft/ -lft -Lft_printf/ -lftprintf

LIBS = libft/libft.a ft_printf/libftprintf.a
FLAGS = -Wall -Wextra -Werror -Iinc/ 
CC = gcc
RM = @rm -fv
.PHONY: all, test, clean, fclean, re, force

all: $(NAME)

force:
	@true

libft/libft.a: force
	make -C libft/

ft_printf/libftprintf.a: force inc/libft.h
	make -C ft_printf/

inc/libft.h: libft/libft.h
	cp -f libft/libft.h $@

inc/ft_printf.h: ft_printf/ft_printf.h
	cp -f ft_printf/ft_printf.h $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c inc/filler.h inc/libft.h inc/ft_printf.h inc/get_next_line.h
	@mkdir $(OBJ_DIR) &> /dev/null || true
	$(CC) $(FLAGS) -o $@ -c $< -Iinc/

$(NAME): $(LIBS) $(OBJ) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJ)
	cp -f $@ players/$@

clean:
	@echo "Cleaning objects:"
	$(MAKE) -C libft/ fclean
	$(MAKE) -C ft_printf/ fclean
	$(RM) $(OBJ) $(ALT_FILE:%=$(OBJ_DIR)/%.o)

fclean: clean
	@echo "Cleaning target:"
	$(RM) $(NAME)

re: fclean all
