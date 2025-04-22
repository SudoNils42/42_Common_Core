# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 11:32:19 by nbonnet           #+#    #+#              #
#    Updated: 2025/04/18 14:38:38 by lfaria-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

PATH_GNL = ./gnl
PATH_SRCS = ./srcs
PATH_MLX = ./mlx
PATH_LIBFT = ./libft
PATH_OBJS = ./objs

MLX = $(PATH_MLX)/libmlx.a
LIBFT = $(PATH_LIBFT)/libft.a

CC = cc
CFLAGS = -Wall -Werror -g -Wextra -I$(PATH_MLX) -I.

SRCS_GNL =	$(PATH_GNL)/get_next_line.c \
			$(PATH_GNL)/get_next_line_utils.c

SRCS_SRCS = $(PATH_SRCS)/main.c \
			$(PATH_SRCS)/display_map_3d.c \
			$(PATH_SRCS)/keyboard_movements.c \
			$(PATH_SRCS)/player.c \
			$(PATH_SRCS)/check_map.c \
			$(PATH_SRCS)/init.c \
			$(PATH_SRCS)/bonus.c \
			$(PATH_SRCS)/free.c \
			$(PATH_SRCS)/draw.c \
			$(PATH_SRCS)/utils.c \
			$(PATH_SRCS)/more_map_validation.c \
			$(PATH_SRCS)/dda_loop.c \
			$(PATH_SRCS)/check_map_utils.c \
			$(PATH_SRCS)/read_map_utils.c \
			$(PATH_SRCS)/ray_functions.c

OBJS_GNL = $(SRCS_GNL:.c=.o)
OBJS_SRCS = $(SRCS_SRCS:$(PATH_SRCS)/%.c=$(PATH_OBJS)/%.o)

OBJS = $(OBJS_GNL) $(OBJS_SRCS)

all: $(LIBFT) $(MLX) $(NAME)

$(PATH_OBJS):
	mkdir -p $(PATH_OBJS)

$(PATH_OBJS)/%.o: $(PATH_SRCS)/%.c | $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@

$(PATH_GNL)/%.o: $(PATH_GNL)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(PATH_MLX) -lmlx -lX11 -lXext -lm -o $(NAME)

$(MLX):
	make -C $(PATH_MLX)

$(LIBFT):
	make -C $(PATH_LIBFT)

clean:
	rm -rf $(PATH_OBJS)/*.o
	rm -rf $(PATH_GNL)/*.o
	make clean -C $(PATH_LIBFT)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(PATH_OBJS)
	make fclean -C $(PATH_LIBFT)

norm:
	@norminette $(SRCS_GNL) $(SRCS_SRCS) $(PATH_LIBFT) $(PATH_SRCS)/cub3d.h

re: fclean all

.PHONY: all clean fclean re norm