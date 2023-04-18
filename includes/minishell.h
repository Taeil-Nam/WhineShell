/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:30:42 by tnam              #+#    #+#             */
/*   Updated: 2023/04/18 21:35:35 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <errno.h>
# include "libft.h"

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAILURE -1

typedef	struct s_node
{
	void			*content;
	struct s_node	*next_node;
	struct s_node	*prev_node;
}	t_node;

typedef struct s_list
{
	t_node			*front_node;
	t_node			*back_node;
	t_node			*cur_node;
}	t_list;

typedef struct s_info
{
	int				argc;
	char			**argv;
	t_list			mini_envp;
}	t_info;

typedef struct s_parse
{
	char *argv;
}	t_parse;


typedef struct s_minishell
{
	t_info *info;
	t_parse *parse;
}	t_minishell;

/* 0_init */
void	ft_mini_envp_init(char **envp, t_list *mini_envp);


/* ft_list */
t_list	ft_list_init(void);
int		ft_list_push_back(void *content, t_list *list);
int		ft_list_del_node(t_list *list, t_node *node);
void	ft_list_clear(t_list *list);

/* utils */
int		ft_error(char *msg, int error_code);

#endif