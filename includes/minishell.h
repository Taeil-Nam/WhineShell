/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:30:42 by tnam              #+#    #+#             */
/*   Updated: 2023/04/28 20:05:10 by tnam             ###   ########.fr       */
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

typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIRECT,
}	t_token_type;

typedef struct s_node
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

typedef struct s_token
{
	t_token_type	type;
	char			*str;
}	t_token;

typedef struct s_info
{
	int				argc;
	char			**argv;
	t_list			mini_envp;
}	t_info;

typedef struct s_parse
{
	char			*line;
	size_t			line_i;
	size_t			token_count;
	t_token			*tokens;
	size_t			tokens_i;
	t_token			*token;
	char			*temp_str;
	size_t			temp_str_len;
	size_t			start_i;
	size_t			str_i;
	int				squote_flag;
	char			*target_env;
	char			*env_val;
	size_t			env_val_len;
	char			*old_str;
	char			*new_str;
}	t_parse;

typedef struct s_minishell
{
	t_info	*info;
	t_parse	*parse;
}	t_minishell;

/* 0_init */
void	ft_init(int argc, char **argv, char **envp, t_minishell *mini);
void	ft_sig_init(void);
void	ft_mini_envp_init(char **envp, t_info *info);

/* 1_parse */
int		ft_parse(t_minishell *mini, t_info *info, t_parse *parse);
int		ft_count_token(t_parse *parse);
int		ft_tokenization(t_parse *parse);
int		ft_make_token(t_parse *parse, t_token_type type);
int		ft_convert_env(t_info *info, t_parse *parse);

/* ft_list */
t_list	ft_list_init(void);
int		ft_list_push_back(void *content, t_list *list);
int		ft_list_del_node(t_list *list, t_node *node);
void	ft_list_clear(t_list *list);

/* utils */
int		ft_error(char *msg, int error_code);
int		ft_is_space(char c);
int		ft_is_operator(char c);
int		ft_is_redirect(char c);
int		ft_is_quote(char c);
int		ft_is_env(t_info *info, t_parse *parse);
void	ft_free_tokens(t_parse *parse);

#endif