NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils1.c \
		ft_printf_utils2.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJS_B)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY : all clean fclean re