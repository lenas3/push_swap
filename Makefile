NAME = push_swap
SRCS = push_swap.c \
	   utils.c \

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
FT_PRINTF_LIB = ./ft_printf/libftprintf.a


all : $(NAME)

$(NAME) : $(OBJS) $(FT_PRINTF_LIB)

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY : all clean fclean re