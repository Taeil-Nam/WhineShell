/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:49:54 by jeekpark          #+#    #+#             */
/*   Updated: 2023/05/24 19:55:32 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit_builtin(t_list *mini_envp, t_parse *parse, t_exec *exec)
{
	ft_list_clear(mini_envp);
	ft_free_all(parse, exec);
	exit(EXIT_SUCCESS);
}
