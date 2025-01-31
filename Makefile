NAME = cub3D
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS =  -Wall -Wextra -Werror
RM = rm -f
LIBFTDIR = libft/
LIBXDIR = minilibx-linux/
OBJ_DIR = obj/
SRC_DIR = srcs/
OBJ = ${SRC:.c=.o}
INCLUDE = -L $(LIBFTDIR) -lft -L $(LIBXDIR) -lmlx_Linux -lXext -lX11 -lm
SRC = $(shell find $(SRC_DIR) -type f -name "*.c")

$(NAME): $(OBJ)
	make -C ${LIBFTDIR}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME} ${INCLUDE}
	
all: $(NAME)

.c.o:
	$(CC) -c $< -o ${<:.c=.o}
 
clean:
	$(RM) $(OBJ) ${NAME}
	@cd ${LIBFTDIR} && ${MAKE} clean

fclean: clean
	$(RM) $(NAME)
	@cd ${LIBFTDIR} && ${MAKE} fclean

re: fclean all

.PHONY: all clean fclean re
