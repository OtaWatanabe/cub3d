NAME = cub3D
OBJ = $(SRS:.c=.o)
CC = cc
CFLAGS =  -Wall -Wextra -Werror
# CFLAGS =  -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -f
LIBFTDIR = libft/
LIBXDIR = minilibx-linux/
OBJ_DIR = obj/
SRCS_DIR = srcs/
OBJ = ${SRCS:.c=.o}
INCLUDE = -L $(LIBFTDIR) -lft -L $(LIBXDIR) -lmlx_Linux -lXext -lX11 -lm 
SRCS = srcs/controls/mouse.c srcs/controls/movement_collision.c srcs/controls/movement.c srcs/controls/rotation.c \
       srcs/events/close_window.c srcs/events/key_press.c srcs/events/key_release.c \
	   srcs/free/exit.c srcs/free/free.c \
	   srcs/init/init_frame.c srcs/init/init_key_state.c srcs/init/init_mlx.c srcs/init/init_player_state.c srcs/init/init_vars.c \
	   srcs/map/map_connected.c srcs/map/map_dim.c srcs/map/map_enclosed.c srcs/map/map_expand.c srcs/map/map_interior_blanks.c srcs/map/map_utils.c srcs/map/map_validate.c srcs/map/map_visited.c \
	   srcs/minimap/minimap_player.c srcs/minimap/minimap.c \
	   srcs/mlx_helper/mlx_helper.c \
	   srcs/parse/parse_color.c srcs/parse/parse_cub.c srcs/parse/parse_error.c srcs/parse/parse_map_utils.c srcs/parse/parse_map.c srcs/parse/parse_tex_utils.c srcs/parse/parse_tex.c srcs/parse/parse_utils.c \
	   srcs/render/clear_frame.c srcs/render/draw_utils.c srcs/render/raycast_utils.c srcs/render/raycast.c srcs/render/render_frame.c \
	   srcs/main.c

$(NAME): $(OBJ)
	make -C ${LIBFTDIR}
	make -C ${LIBXDIR}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME} ${INCLUDE}
	
all: $(NAME)

.c.o:
	$(CC) -c ${CFLAGS} $< -o ${<:.c=.o}
 
clean:
	$(RM) $(OBJ) ${NAME}
	@cd ${LIBFTDIR} && ${MAKE} clean
	@cd ${LIBXDIR} && ${MAKE} clean

fclean: clean
	$(RM) $(NAME)
	@cd ${LIBFTDIR} && ${MAKE} fclean
	@cd ${LIBXDIR} && ${MAKE} clean

re: fclean all

.PHONY: all clean fclean re
