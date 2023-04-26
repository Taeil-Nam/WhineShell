# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 17:24:05 by tnam              #+#    #+#              #
#    Updated: 2023/04/26 17:35:33 by tnam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f

INCLUDES		=	includes/

LIBFT_DIR		=	srcs/libft
LIBFT			=	libft.a
LIBFT_C			=	-L$(LIBFT_DIR) -lft

SRCS			=	srcs/main.c							\
					srcs/utils/ft_error.c				\
					srcs/utils/ft_is_space.c			\
					srcs/utils/ft_is_operator.c			\
					srcs/utils/ft_is_redirect.c			\
					srcs/utils/ft_is_quote.c			\
					srcs/ft_list/ft_list_del_node.c		\
					srcs/ft_list/ft_list_init.c			\
					srcs/ft_list/ft_list_push_back.c	\
					srcs/ft_list/ft_list_clear.c		\
					srcs/0_init/ft_init.c				\
					srcs/0_init/ft_sig_init.c			\
					srcs/0_init/ft_mini_envp_init.c		\
					srcs/1_parsing/ft_parse.c			\
					srcs/1_parsing/ft_count_token.c		\
					
					
OBJS			=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) all
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_C) -o $(NAME) \
	-lreadline -L${HOME}/.brew/opt/readline/lib

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -I${HOME}/.brew/opt/readline/include -c $< -o $@ 

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