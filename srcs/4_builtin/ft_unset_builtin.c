/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:45:43 by jeekpark          #+#    #+#             */
/*   Updated: 2023/05/24 19:55:32 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node	*ft_unset_builtin_find_node(char *to_find, t_list *list)
{
	t_node	*cur;
	size_t	to_find_len;

	cur = list->front_node;
	to_find_len = ft_strlen(to_find);
	while (cur)
	{
		if (ft_strncmp(to_find, cur->content, to_find_len) == 0)
			return (cur);
		cur = cur->next_node;
	}
	cur = list->front_node;
	while (cur)
	{
		if (ft_strncmp(to_find, cur->content, to_find_len + 1) == -61)
			return (cur);
		cur = cur->next_node;
	}
	return (NULL);
}

static void	ft_unset_builtin_del_node(t_info *info, t_exec_info *exec_info)
{
	size_t	i;
	t_node	*to_delete;

	i = 1;
	while (exec_info->cmd[i])
	{
		to_delete
			= ft_unset_builtin_find_node(exec_info->cmd[i], &(info->mini_envp));
		if (to_delete)
			ft_list_del_node(&(info->mini_envp), to_delete);
		i++;
	}
}

int	ft_unset_builtin(t_info *info, t_exec_info *exec_info)
{
	if (exec_info->cmd[1] == NULL)
		exit(EXIT_SUCCESS);
	else
		ft_unset_builtin_del_node(info, exec_info);
	exit(EXIT_SUCCESS);
}
