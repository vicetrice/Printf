LIB = ar rcs
RM = rm -f


CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRC =   ft_aux.c  ft_printf.c  ft_univ.c \

OBJ = $(SRC:.c=.o)
INCLUDE = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
