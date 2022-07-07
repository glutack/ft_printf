NAME	=	libftprintf.a
SRCS	=	ft_printf.c
OBJS	=	${SRCS:.c=.o}
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
CC		=	gcc

all: $(NAME)

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "Objetos creados"

$(NAME): ${OBJS} 
	@${CC} -c ${CFLAGS} ${SRCS}
	@ar crs ${NAME} ${OBJS}
	@echo "Librería creada"

clean: 
	@${RM} ${OBJS}
	@echo "Objetos eliminados"

fclean: clean
	@${RM} ${NAME}
	@echo "Librería eliminada"

re: fclean all
	@echo ":D"

.PHONY: all clean fclean re