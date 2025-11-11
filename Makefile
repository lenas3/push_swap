NAME = push_swap
SRCS = push_swap.c \
	   push.c \
	   radix.c \
	   re_rotate.c \
	   rotate.c \
	   sort_five.c \
	   sort_three.c \
	   split.c \
	   swap.c \
	   utils.c \
	   utils2.c
	   
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY : all clean fclean re