CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = rush-02
SRCDIR = srcs
INCDIR = includes
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)

all : $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm -f $(OBJS) $(TARGET)

fclean : clean
	rm -f $(TARGET)

re: fclean all
