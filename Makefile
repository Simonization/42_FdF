# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slangero <slangero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 16:06:30 by slangero          #+#    #+#              #
#    Updated: 2024/12/08 17:06:07 by slangero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast

RM = rm -rf

MLX_DIR = ./mlx
MLX = -lmlx -Lmlx -framework OpenGl -framework AppKit
MLX_OBJ = -Imlx -c
MLX_LIB = -L $(MLX_DIR) -lmlx

SRCS = source/main.c source/window.c \
       source/parse.c source/map_dimensions.c \
	   source/point.c source/draw.c \
	   utils/get_next_line.c utils/get_next_line_utils.c \
       utils/free.c utils/error.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@make -C libft
	@$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -g $(MLX_LIB) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -I. -c $< -o $@
	
clean :
	@make clean -C libft
	@make clean -C mlx
	@$(RM) $(OBJS)
	

fclean : clean
	@make fclean -C libft
	@$(RM) $(NAME)

re : fclean all 

.PHONY: all clean fclean re
