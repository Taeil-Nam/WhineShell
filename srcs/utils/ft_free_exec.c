/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exec_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:04:50 by tnam              #+#    #+#             */
/*   Updated: 2023/05/22 13:47:21 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_exec(t_exec_info *exec_arr, size_t exec_arr_i)
{
	size_t	i;

	i = 0;
	while (i < exec_arr_i)
	{
		free(exec_arr[i].cmd);
		free(exec_arr[i].redirect);
		i++;
	}
	free(exec_arr);
}
