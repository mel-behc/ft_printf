CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
HEADER = ./include/
SRC = ./srcs/ft_check.c ./srcs/ft_putchar.c ./srcs/ft_putnbr.c \
	./srcs/ft_toupper.c ./srcs/ft_printf.c ./srcs/ft_puthexa.c \
	./srcs/ft_putstr.c ./srcs/ft_uputnbr.c


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)
	ar rcs $(NAME) $@

clean: 
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)

re: fclean all

