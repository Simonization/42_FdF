# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slangero <slangero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 16:06:30 by slangero          #+#    #+#              #
#    Updated: 2024/09/10 18:28:08 by slangero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast

RM = rm -rf

MLX_DIR = ./mlx
MLX_PATH = mlx/libmlx.a	
MLX = -lmlx -Lmlx -framework OpenGl -framework AppKit
MLX_OBJ = -Imlx -c
MLX_LIB = -L $(MLX_DIR) -lmlx

SRCS = source/main.c
		# source/window.c source/error_management.c \
	   	# source/parse.c source/get_next_line.c source/get_next_line_utils.c \
	  	# source/free.c source/count.c source/draw.c source/projection.c \
		# source/input_handling.c source/key_functions.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@make -C libft
	@$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -g $(MLX_LIB) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
fclean : clean
	@make fclean -C libft
	@$(RM) fdf
	
clean :
	@make clean -C libft
	@$(RM) source/*.o
	@make clean -C mlx

re : fclean all 

.PHONY: all clean fclean re
