/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:25:50 by tnam              #+#    #+#             */
/*   Updated: 2023/04/28 20:02:00 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_parse_init(t_parse *parse)
{
	parse->line_i = 0;
	while (ft_is_space(parse->line[parse->line_i]))
		parse->line_i++;
	parse->token_count = 0;
	parse->tokens_i = 0;
	parse->start_i = 0;
	parse->str_i = 0;
	parse->squote_flag = FALSE;
}

static int	ft_ready_tokenization(t_parse *parse)
{
	parse->line_i = 0;
	parse->tokens = (t_token *)ft_calloc(parse->token_count, sizeof(t_token));
	if (parse->tokens == NULL)
		return (ft_error("Failed calloc tokens.", FAILURE));
	return (SUCCESS);
}

int	ft_parse(t_minishell *mini, t_info *info, t_parse *parse)
{
	ft_parse_init(parse);
	if (ft_count_token(parse) == FAILURE)
		return (FAILURE);
	if (ft_ready_tokenization(parse) == FAILURE)
		return (FAILURE);
	if (ft_tokenization(parse) == FAILURE)
	{
		ft_free_tokens(parse);
		return (FAILURE);
	}
	if (ft_convert_env(info, parse) == FAILURE)
	{
		ft_free_tokens(parse);
		return (FAILURE);
	}
	(void)mini; // dummy
	return (SUCCESS);
}
