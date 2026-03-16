# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 15:15:21 by nbonnet           #+#    #+#              #
#    Updated: 2025/06/03 15:15:43 by nbonnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = clapTrap
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = $(wildcard srcs/*.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re