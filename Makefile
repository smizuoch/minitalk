 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 15:43:29 by smizuoch          #+#    #+#              #
#    Updated: 2023/08/27 12:04:20 by smizuoch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server

NAME2 = client

BONUS1 = server_bonus

BONUS2 = client_bonus

SRCS = server.c client.c

BONUS = server_bonus.c client_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

LIBFT_DIR = libft

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_DIR)

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS) $(LIBFT)
	$(CC) $(LIBFT) -o $(NAME1) server.o

$(NAME2): $(OBJS) $(LIBFT)
	$(CC) $(LIBFT) -o $(NAME2) client.o

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus: $(BONUS1) $(BONUS2)

$(BONUS1): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(LIBFT) -o $(BONUS1) server_bonus.o

$(BONUS2): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(LIBFT) -o $(BONUS2) client_bonus.o

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME1) $(NAME2) $(LIBFT) $(BONUS1) $(BONUS2)

re: fclean all

.PHONY: all clean fclean re
