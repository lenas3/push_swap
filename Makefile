NAME = push_swap
SRCS = push_swap.c \
	   push.c \
	   re_rotate.c \
	   rotate.c \
	   split.c \
	   swap.c \
	   utils.c \
	   

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY : all clean fclean re