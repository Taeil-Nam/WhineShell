/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:19:03 by jeekpark          #+#    #+#             */
/*   Updated: 2023/05/23 18:48:54 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_builtin(t_info *info)
{
	t_node	*cur;

	cur = info->mini_envp.front_node;
	while (cur)
	{
		printf("%s\n", (char *)(cur->content));
		cur = cur->next_node;
	}
	exit (EXIT_SUCCESS);
}
