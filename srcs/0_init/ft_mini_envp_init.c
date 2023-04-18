/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_envp_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:15:44 by jeekpark          #+#    #+#             */
/*   Updated: 2023/04/18 21:35:38 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_mini_envp_init(char **envp, t_list *mini_envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		ft_list_push_back(ft_strdup(envp[i]), mini_envp);
		i++;
	}
}
