/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:49:54 by jeekpark          #+#    #+#             */
/*   Updated: 2023/05/25 16:16:56 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	ft_exit_builtin_isnum(t_exec *exec)
{
	size_t	i;

	i = 0;
	if ((exec->exec_arr[exec->exec_arr_i].cmd[1][0] == '-')
		|| (exec->exec_arr[exec->exec_arr_i].cmd[1][0] == '+'))
		i++;
	while (exec->exec_arr[exec->exec_arr_i].cmd[1][i])
	{
		if (ft_isnum(exec->exec_arr[exec->exec_arr_i].cmd[1][i]))
			i++;
		else
		{
			ft_printf_err("exit: %s: numeric argument required\n",
				exec->exec_arr[exec->exec_arr_i].cmd[1]);
			return (FAILURE);
		}
	}
	if (i == 1)
	{
		ft_printf_err("exit: %s: numeric argument required\n",
			exec->exec_arr[exec->exec_arr_i].cmd[1]);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_exit_builtin(t_list *mini_envp, t_parse *parse, t_exec *exec)
{
	int	exit_value;

	if ((exec->exec_arr[exec->exec_arr_i].cmd[1]) == NULL)
	{
		ft_list_clear(mini_envp);
		ft_free_all(parse, exec);
		exit(0);
	}
	if (exec->exec_arr[exec->exec_arr_i].cmd[2])
	{
		ft_printf_err("exit: too many arguments\n");
		g_child_exit_code = 1;
		return (FAILURE);
	}
	if (ft_exit_builtin_isnum(exec) == FAILURE)
		return (FAILURE);
	exit_value = ft_atoi(exec->exec_arr[exec->exec_arr_i].cmd[1]);
	ft_list_clear(mini_envp);
	ft_free_all(parse, exec);
	exit(exit_value);
}
