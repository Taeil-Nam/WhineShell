/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:00:35 by jeekpark          #+#    #+#             */
/*   Updated: 2023/05/24 19:55:32 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_export_builtin_arg(t_info *info, t_exec_info *exec_info)
{
	size_t	i;

	i = 1;
	while (exec_info->cmd[i])
	{
		ft_list_push_back(ft_strdup(exec_info->cmd[i]), &(info->mini_envp));
		i++;
	}
}

static void	ft_export_builtin_no_arg(t_list *list)
{
	t_node	*cur;

	cur = list->front_node;
	while (cur)
	{
		printf("declare -x %s\n", (char *)(cur->content));
		cur = cur->next_node;
	}
}

int	ft_export_builtin(t_info *info, t_exec_info *exec_info)
{
	if (exec_info->cmd[1] == NULL)
		ft_export_builtin_no_arg(&(info->mini_envp));
	else
		ft_export_builtin_arg(info, exec_info);
	exit(EXIT_SUCCESS);
}
