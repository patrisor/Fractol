# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: patrisor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 14:04:03 by patrisor          #+#    #+#              #
#    Updated: 2019/06/18 05:39:01 by patrisor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX = ./minilibx_macos/

NAME = fractol
SRCS_DIR = ./src/
INCLUDES = ./includes/
OBJ = ./obj/
RM = /bin/rm -Rf

FILES = main choose_fractal color fractal_funcs fractal_utils \
	fractal_escape_time fractal_setup_0 fractal_setup_1 \
	image render mouse_hooks loop_hooks key_hooks
CFILES = $(patsubst %, $(SRCS_DIR)%.c, $(FILES))
OFILES = $(patsubst %, %.o, $(FILES))
CFLAGS = -Wall -Wextra -Werror -O2 -funroll-loops

#mlx library
MLX_LIB	= $(addprefix $(MLX), mlx.a)
MLX_INC = -I $(MLX)
MLX_LINK = -L $(MLX) -l mlx -framework OpenGL -framework AppKit

#libft
LFT = ./libft/
LFT_LIB = $(addprefix $(LFT), libft.a)
LFT_INC = -I $(LFT)includes/
LFT_LINK = -L $(LFT) -l ft

all: $(MLX_LIB) $(LFT_LIB) $(NAME)

$(OFILES):
	mkdir $(OBJ)
	gcc $(CFLAGS) -c -I$(INCLUDES) $(MLX_INC) $(LFT_INC) $(CFILES)

$(LFT_LIB):
	make -C $(LFT)

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OFILES)
	gcc $(CFLAGS) $(OFILES) $(MLX_LINK) $(LFT_LINK) -o $(NAME)
	mv *.o $(OBJ)

clean:
	make -C $(MLX) clean
	make -C $(LFT) clean
	$(RM) $(OBJ)
	$(RM) *.o

fclean: clean
	make -C $(LFT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
