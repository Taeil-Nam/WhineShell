# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 17:24:05 by tnam              #+#    #+#              #
#    Updated: 2023/04/18 21:35:33 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

CC				=	cc
CFLAGS			=	#-Wall -Wextra -Werror
RM				=	rm -f

INCLUDES		=	includes/

LIBFT_DIR		=	srcs/libft
LIBFT			=	libft.a
LIBFT_C			=	-L$(LIBFT_DIR) -lft

SRCS			=	srcs/main.c							\
					srcs/utils/ft_error.c				\
					srcs/ft_list/ft_list_del_node.c		\
					srcs/ft_list/ft_list_init.c			\
					srcs/ft_list/ft_list_push_back.c	\
					srcs/ft_list/ft_list_clear.c		\
					srcs/0_init/ft_mini_envp_init.c		\
					
					
OBJS			=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) all
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_C) -o $(NAME) -lreadline

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY : all bonus clean fclean re