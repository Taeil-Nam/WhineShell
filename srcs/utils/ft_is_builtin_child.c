/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builtin_child.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:26:37 by tnam              #+#    #+#             */
/*   Updated: 2023/05/25 13:20:32 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_builtin_child(t_exec_info *exec_info)
{
	if (exec_info->cmd_path == NULL)
		return (FALSE);
	if (ft_strncmp(exec_info->cmd[0], "echo", ft_strlen("echo") + 1) == 0
		|| ft_strncmp(exec_info->cmd[0], "pwd", ft_strlen("pwd") + 1) == 0
		|| ft_strncmp(exec_info->cmd[0], "env", ft_strlen("env") + 1) == 0)
		return (TRUE);
	return (FALSE);
}
