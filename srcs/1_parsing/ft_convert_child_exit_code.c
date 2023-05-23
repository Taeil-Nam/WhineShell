/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_child_exit_code.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:22:44 by tnam              #+#    #+#             */
/*   Updated: 2023/05/23 18:10:39 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_convert_child_exit_code(t_parse *parse)
{
	parse->exit_code = ft_itoa(g_child_exit_code);
	if (parse->exit_code == NULL)
		return (FAILURE);
	parse->token->str[parse->str_i] = '\0';
	parse->old_str = ft_strjoin(parse->token->str, parse->exit_code);
	if (parse->old_str == NULL)
	{
		free(parse->exit_code);
		return (FAILURE);
	}
	parse->new_str
		= ft_strjoin(parse->old_str, &parse->token->str[parse->str_i + 2]);
	if (parse->new_str == NULL)
	{
		free(parse->exit_code);
		free(parse->old_str);
		return (FAILURE);
	}
	free(parse->token->str);
	parse->token->str = parse->new_str;
	parse->str_i += ft_strlen(parse->exit_code) - 1;
	free(parse->exit_code);
	free(parse->old_str);
	return (SUCCESS);
}
