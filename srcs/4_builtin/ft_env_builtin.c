/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:19:03 by jeekpark          #+#    #+#             */
/*   Updated: 2023/05/23 17:32:53 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    ft_env_builtin(t_info *info, t_exec_info *exec_info)
{
    t_node *cur;

    cur = info->mini_envp.front_node;
    while (cur)
    {
        printf("%s\n", (char *)(cur->content));
        cur = cur->next_node;
    }
    return (SUCCESS);
}
