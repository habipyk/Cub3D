NAME		= cub3D

LBFT		= libft/libft.a

GNL			= get_next_line/get_next_line.a

MLX			= mlx/libmlx.a

SRCS		=	arg_check.c file_handler.c graphics.c init.c \
				input.c main.c map_check.c map_processing.c map_utils.c \
				map_utils2.c map_utils3.c map_utils4.c move_handler.c \
				player_direction.c raycasting.c render.c rgb.c utils.c

CC			= gcc

FLAGS		= -Wall -Wextra -Werror -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME)	: $(LBFT) $(GNL) $(MLX) $(SRCS)
		@$(CC) $(SRCS) $(MLX) $(LBFT) $(FLAGS) $(GNL) -o $(NAME)

$(LBFT):
		@make -C libft

$(GNL):
		@make -C get_next_line
	
$(MLX):
		@make -C mlx

clean :
		@rm -rf $(NAME)
		@make fclean -C libft
		@make fclean -C get_next_line
		@make clean -C mlx

fclean : clean

re : clean all

bonus :
		@echo "nothing"

.PHONY : all clean fclean re bonus