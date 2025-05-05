NAME = libftprintf.a

MAKE = make

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I includes -I ft_libft

RM = rm -f

SRCS = sources/printf.c sources/put_out_1.c sources/put_out_2.c

OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./ft_libft
	cp ft_libft/libft.a $@
	ar rcs $@ $?

sources/%.o : sources%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean :
	$(MAKE) -C ./ft_libft clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C ./ft_libft fclean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean fclean all
