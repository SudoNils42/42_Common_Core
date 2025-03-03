# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 17:47:18 by nbonnet           #+#    #+#              #
#    Updated: 2024/12/11 21:10:41 by nbonnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
PRINTF = ./ft_printf/libftprintf.a
LIBFT = ./ft_printf/libft/libft.a

all: $(NAME_SERVER) $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_SERVER): $(OBJS_SERVER) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(PRINTF) $(LIBFT) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF) $(LIBFT) -o $(NAME_CLIENT)

$(LIBFT):
	make -C ./ft_printf/libft

$(PRINTF):
	make -C ./ft_printf

clean:
	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT)
	make clean -C ./ft_printf
	make clean -C ./ft_printf/libft


fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make fclean -C ./ft_printf
	make fclean -C ./ft_printf/libft

re: fclean all

.PHONY: all clean fclean re
