NAME = bsq
CC = gcc -Wall -Wextra -Werror
SRCS = srcs/*.c
OBJS = $(SRCS:.c=.o)
HEADERS = includes
RM = rm -f

$(NAME):
	$(CC) -o $(NAME) $(SRCS) -I $(HEADERS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
