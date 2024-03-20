CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
LIB_DIR = ./libft
LIB = libft.a
INCLUDE = push_swap.h
COMMON_SRCS = list_op.c stack_op.c stack_op2.c\
			  utils.c valid_parse.c index_sort.c
COMMON_OBJS = list_op.o stack_op.o stack_op2.o\
			  utils.o valid_parse.o index_sort.o
MAN_SRCS = main.c rotation.c sort3.c get_min_rotation.c\
		   push_swap.c
MAN_OBJS = main.o rotation.o sort3.o get_min_rotation.o\
		   push_swap.o
BNS_SRCS = checker.c
BNS_OBJS = checker.o
BNS = checker

ifdef IS_BONUS
NAME = checker
SRCS = $(COMMON_SRCS) $(BNS_SRCS)
OBJS = $(COMMON_OBJS) $(BNS_OBJS)
else 
NAME = push_swap
SRCS = $(COMMON_SRCS) $(MAN_SRCS)
OBJS = $(COMMON_OBJS) $(MAN_OBJS)
endif

all: $(NAME)

bonus:
	make IS_BONUS=1 all

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(LIB_DIR)/$(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -L$(LIB_DIR) -lft

$(LIB_DIR)/$(LIB):
	make -C $(LIB_DIR)

clean:
	rm -f $(COMMON_OBJS) $(MAN_OBJS) $(BNS_OBJS)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BNS)
	make -C $(LIB_DIR) fclean	

re:
	make fclean
	make all

.PHONY: all, clean, fclean, re, bonus