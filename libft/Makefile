CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = libft.h
NAME = libft.a
SRCS = ft_atoi.c ft_isalnum.c ft_isalpha.c ft_bzero.c \
	   ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c \
	   ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strchr.c\
	   ft_strlen.c ft_strncmp.c ft_strrchr.c\
	   ft_tolower.c ft_toupper.c ft_memchr.c ft_memcmp.c \
	   ft_calloc.c ft_memcpy.c ft_memmove.c ft_substr.c \
	   ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	   ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_strnstr.c \
	   ft_printf.c ft_puthex.c ft_putdec.c ft_strlen.c ft_putusg.c \
	   get_next_line.c get_next_line_utils.c
BNS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
		   ft_lstsize_bonus.c ft_lstlast_bonus.c \
		   ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		   ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
		
OBJS = $(SRCS:.c=.o)
BNS_OBJS = $(BNS_SRCS:.c=.o)

all: $(NAME)
	
$(NAME): make_mandatory

bonus: make_bonus

clean:
	rm -f $(OBJS) $(BNS_OBJS)
	rm -f make_mandatory make_bonus

fclean: clean
	rm -f $(NAME)

make_mandatory : $(OBJS)
	ar rcs $(NAME) $^
	touch $@

make_bonus : $(BNS_OBJS)
	ar rcs $(NAME) $^
	touch $@

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@ 

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re
