/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:44:04 by jeekpark          #+#    #+#             */
/*   Updated: 2023/05/23 17:47:13 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd_builtin(void)
{
	char path[256];

	if (getcwd(path, sizeof(path)))
        printf("Current directory: %s\n", path);
    else
        return (FAILURE);
    return (SUCCESS);
}