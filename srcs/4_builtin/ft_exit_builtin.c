/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:49:54 by jeekpark          #+#    #+#             */
/*   Updated: 2023/05/23 17:52:14 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_exit_builtin(t_list *mini_envp, t_parse *parse, t_exec *exec)
{
	ft_list_clear(mini_envp);
	ft_free_all(parse, exec);
	return (0);
}