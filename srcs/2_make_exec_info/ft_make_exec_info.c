/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_exec_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:24:48 by tnam              #+#    #+#             */
/*   Updated: 2023/05/22 14:03:04 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_get_exec_arr_size(t_parse *parse, t_exec *exec)
{
	size_t	token_index;

	exec->exec_arr_size = 1;
	token_index = 0;
	while (token_index < parse->token_count)
	{
		if (parse->tokens[token_index].type == PIPE)
			exec->exec_arr_size++;
		token_index++;
	}
}

static void	ft_init_exec_info(t_exec_info *exec_info)
{
	exec_info->cmd_path = NULL;
	exec_info->cmd = NULL;
	exec_info->cmd_i = 0;
	exec_info->redirect = NULL;
	exec_info->redirect_i = 0;
	exec_info->use_pipe = FALSE;
}

static int	ft_add_exec_info(t_parse *parse, t_exec *exec)
{
	t_exec_info	*exec_info;
	size_t		exec_arr_i;

	parse->tokens_i = 0;
	exec_arr_i = 0;
	while (exec_arr_i < exec->exec_arr_size)
	{
		exec_info = &exec->exec_arr[exec_arr_i];
		ft_init_exec_info(exec_info);
		if (ft_set_exec_info(parse, exec_info) == FAILURE)
		{
			ft_free_exec(exec->exec_arr, exec_arr_i);
			return (FAILURE);
		}
		exec_arr_i++;
	}
	return (SUCCESS);
}

int	ft_make_exec_info(t_parse *parse, t_exec *exec)
{
	ft_get_exec_arr_size(parse, exec);
	exec->exec_arr
		= (t_exec_info *)malloc(sizeof(t_exec_info) * exec->exec_arr_size);
	if (exec->exec_arr == NULL)
	{
		ft_free_tokens(parse, parse->token_count);
		return (FAILURE);
	}
	if (ft_add_exec_info(parse, exec) == FAILURE)
	{
		ft_free_tokens(parse, parse->token_count);
		return (FAILURE);
	}
	return (SUCCESS);
}