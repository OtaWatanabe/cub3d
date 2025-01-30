NAME = cub3D
OBJ = $(SRC:.c=.o)
CC = cc
# CFLAGS =  -Wall -Wextra -Werror
CFLAGS = -lm
RM = rm -f
# LIBFTDIR = libft/
LIBXDIR = minilibx-linux/

OBJ = $(SRC:.c=.o)
# INCLUDE = -L $(LIBFTDIR) -lft -L $(LIBXDIR) -lmlx_Linux -lXext -lX11
INCLUDE = -L $(LIBXDIR) -lmlx_Linux -lXext -lX11

SRC = main.c

$(NAME): $(OBJ)
	${CC} ${CFLAGS} ${OBJ} -o ${NAME} ${INCLUDE}
	
all: $(NAME)

.c.o:
	$(CC) -c $< -o ${<:.c=.o}
 
clean:
	$(RM) $(OBJ) ${NAME}

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re