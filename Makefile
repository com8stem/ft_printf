TARGET = a.out
NAME = libftprintf.a

SRCS = ft_itoa.c ft_itoa_unsign.c ft_printf_hex.c ft_printf_main.c ft_printf_print.c\
		testmain.c
OBJS = $(SRCS:.c=.o)
HEADER = ft_printf.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(TARGET)

$(TARGET): $(NAME)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
