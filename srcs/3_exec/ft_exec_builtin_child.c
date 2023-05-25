/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_builtin_child.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:31:00 by tnam              #+#    #+#             */
/*   Updated: 2023/05/25 17:20:28 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec_builtin_child(t_info *info, t_exec_info *exec_info)
{
	if (ft_strncmp(exec_info->cmd[0], "echo", ft_strlen("echo") + 1) == 0)
		ft_echo_builtin(exec_info);
	if (ft_strncmp(exec_info->cmd[0], "pwd", ft_strlen("pwd") + 1) == 0)
		ft_pwd_builtin();
	if (ft_strncmp(exec_info->cmd[0], "env", ft_strlen("env") + 1) == 0)
		ft_env_builtin(info);
}
