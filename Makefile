NAME		=	cub3D
FLAGS		=	-Wall -Wextra -Werror
MLX			=	-L ./minilibx/ -l mlx
HDRS		=	./HDRS
FRAMEWORKS	=	-framework OpenGL -framework AppKit -lz
GNL			=	./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
SRCS		= 	cub_utils_1.c cub_utils_2.c cub_utils_3.c cub_utils_4.c 		\
				first_person.c lib_sources_1.c lib_sources_2.c lib_sources_3.c	\
				lst.c major_functions.c minus_save.c print_patterns.c			\
				raycasting.c validate_config.c walls.c							\
				write_bmp.c bmp_utils.c validate_map.c main.c

OBJS =	$(SRCS:%.c=%.o)

.PHONY: all clean fclean re

vpath %.c SRCS


all: $(NAME)

libmlx.a:
	make -C minilibx

$(NAME): libmlx.a $(OBJS) $(HDRS)
	gcc $(FLAGS) $(OBJS) $(MLX) $(GNL) $(FRAMEWORKS) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(HDRS) $< -c -o $@

clean:
	rm -f *.o
	make -C minilibx clean

fclean: clean
	rm -f $(NAME)
	make -C minilibx clean

re: fclean all
