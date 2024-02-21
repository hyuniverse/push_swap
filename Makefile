NAME = push_swap

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
LIB_DIR = ./libft
NAME = push_swap
SRCS = main.c list_op.c stack_op.c stack_op2.c\
	   utils.c
OBJS = main.o list_op.o stack_op.o stack_op2.o\
	   utils.o
INCLUDE = push_swap.h

all: $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -L$(LIB_DIR) -lft -lftprintf

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all, clean, fclean, re