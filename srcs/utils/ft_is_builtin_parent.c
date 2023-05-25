/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builtin_parent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:26:37 by tnam              #+#    #+#             */
/*   Updated: 2023/05/25 13:37:23 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_builtin_parent(t_exec_info *exec_info)
{
	if (exec_info->cmd_path == NULL)
		return (FALSE);
	if (ft_strncmp(exec_info->cmd[0], "cd", ft_strlen("cd") + 1) == 0
		|| ft_strncmp(exec_info->cmd[0], "export", ft_strlen("export") + 1) == 0
		|| ft_strncmp(exec_info->cmd[0], "unset", ft_strlen("unset") + 1) == 0
		|| ft_strncmp(exec_info->cmd[0], "exit", ft_strlen("exit") + 1) == 0)
		return (TRUE);
	return (FALSE);
}
