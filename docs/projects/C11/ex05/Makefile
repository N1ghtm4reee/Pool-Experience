CC = gcc
inc = doop.h
CFLAGS = -Wall -Wextra -Werror -I $(inc)
src = do-op.c utils.c operations.c
obj = do-op.o utils.o operations.o

all : do-op

do-op : $(obj)
	$(CC) $(obj) -o do-op
	chmod +x do-op

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(obj)
fclean : clean
	rm -f do-op
