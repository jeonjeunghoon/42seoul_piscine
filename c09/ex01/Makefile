CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
INCS = includes/
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o

all : ${NAME}

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

${NAME}: $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean :
		/bin/rm -f ${OBJS}

fclean : clean
		/bin/rm -f ${NAME}

re: fclean all
