# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 18:15:14 by nbonnet           #+#    #+#              #
#    Updated: 2025/05/14 18:15:47 by nbonnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = unnecessaryViolence
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
