/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:25:50 by tnam              #+#    #+#             */
/*   Updated: 2023/04/26 17:57:12 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse(t_minishell *mini, t_info *info, t_parse *parse)
{
	mini->parse->line_i = 0;
	mini->parse->token_count = 0;
	while (ft_is_space(parse->line[parse->line_i]))
		parse->line_i++;
	if (ft_count_token(parse) == FAILURE)
		return (FAILURE);
	mini = 0; // dummy
	info = 0; // dummy
	return (SUCCESS);
}
