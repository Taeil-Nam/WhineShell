/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:18:06 by tnam              #+#    #+#             */
/*   Updated: 2023/05/24 16:14:49 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_child_exit_code;

void	ft_init(int argc, char **argv, char **envp, t_info *info)
{
	g_child_exit_code = 0;
	info->argc = argc;
	info->argv = argv;
	info->envp = envp;
	ft_mini_envp_init(envp, info);
}
