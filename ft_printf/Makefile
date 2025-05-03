NAME = libftprintf.a

MAKE = make

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = printf.c put_out_1.c put_out_2.c

OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $@
	ar rcs $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean fclean all
