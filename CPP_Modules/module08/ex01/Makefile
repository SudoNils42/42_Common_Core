# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 16:18:17 by nbonnet           #+#    #+#              #
#    Updated: 2025/09/17 17:22:04 by nbonnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS =	srcs/main.cpp \
		srcs/Span.cpp
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