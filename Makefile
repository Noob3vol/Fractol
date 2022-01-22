NAME=fractol

CC=clang
WFLAG=-Wall -Werror -Wextra
DFLAG=-g3 -fsanitize=address

FT_DIR=libft/
FT=libft.a
FT_INC=$(FT_DIR)include/

FT_FLAG= -L$(FT_DIR) -lft

MLX_FLAG= -L$(MLX_DIR) -l$(MLX_NAME)
ifeq ($(shell uname), Linux)

MLX_DIR=mlx_linux
MLX_LIB=$(MLX_FLAG) -lm -lX11 -lXext -lz

else

MLX_DIR=mlx_mac
MLX_LIB=$(MLX_FLAG) -lm -framework OpenGL -framework AppKit

endif

MLX_NAME=mlx
MLX_A=$(MLX_DIR)/libmlx.a
FT_A=$(FT_DIR)/libft.a

SRC_DIR=src/
SRC_NAME=main.c \
		 ft_setup_env.c \
		 ft_draw_utils.c \
		 ft_render_fractol.c \
		 ft_event_manager.c \
		 ft_free_render.c

SRC=$(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ_DIR=obj/
OBJ_NAME=$(SRC_NAME:.c=.o)
OBJ=$(addprefix $(OBJ_DIR), $(OBJ_NAME))

HDR_DIR=include/
HDR_NAME=fractol.h
HDR=$(HDR_DIR)$(HDR_NAME)

INC=-I$(HDR_DIR) -I$(MLX_DIR) -I$(FT_INC)

FLAG=$(MLX_LIB) $(FT_FLAG)

ifeq ($(DEBUG), 1)
	WFLAG	+=	-g
endif

all : $(NAME)

$(FT_A):
	-make -C $(FT_DIR)

$(MLX_A):
	-make -C $(MLX_DIR)

$(NAME): $(FT_A) $(MLX_A) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(FLAG)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDR)
	mkdir -p $(OBJ_DIR)
	$(CC) $(WFLAG) $(INC) -o $@ -c $<

clean:
	-make clean -C $(MLX_DIR)
	-make clean -C $(FT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	-make fclean -C $(FT_DIR)
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all makelib clean fclean bonus re
