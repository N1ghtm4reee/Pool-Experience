CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)
SRCDIR = srcs
INCDIR = includes
SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJ = $(SRC:.c=.o)
LIB = libft.a

all: $(LIB)

$(LIB): $(OBJ)
    ar rc $(LIB) $(OBJ)
    ranlib $(LIB)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(LIB)

re: fclean all
