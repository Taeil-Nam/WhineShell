/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:28:40 by tnam              #+#    #+#             */
/*   Updated: 2023/04/28 17:11:10 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_operator_process(t_parse *parse)
{
	char	redirect_c;

	if (parse->line[parse->line_i] == '|')
	{
		if (ft_make_token(parse, PIPE) == FAILURE)
			return (FAILURE);
	}
	else if (ft_is_redirect(parse->line[parse->line_i]) == TRUE)
	{
		redirect_c = parse->line[parse->line_i];
		if (parse->line[parse->line_i + 1] == redirect_c)
			parse->line_i++;
		if (ft_make_token(parse, REDIRECT) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

static void	ft_quote_process(t_parse *parse)
{
	char	end_quote;

	end_quote = parse->line[parse->line_i];
	parse->line_i++;
	while (parse->line[parse->line_i]
		&& parse->line[parse->line_i] != end_quote)
		parse->line_i++;
}

static int	ft_character_process(t_parse *parse)
{
	while (TRUE)
	{
		if (ft_is_quote(parse->line[parse->line_i]) == TRUE)
			ft_quote_process(parse);
		if (parse->line[parse->line_i + 1] == '\0'
			|| ft_is_space(parse->line[parse->line_i + 1]) == TRUE
			|| ft_is_operator(parse->line[parse->line_i + 1]) == TRUE)
		{
			if (ft_make_token(parse, WORD) == FAILURE)
				return (FAILURE);
			return (SUCCESS);
		}
		parse->line_i++;
	}
	return (SUCCESS);
}

int	ft_tokenization(t_parse *parse)
{
	while (parse->line[parse->line_i])
	{
		if (ft_is_space(parse->line[parse->line_i]) == TRUE)
			;
		else if (ft_is_operator(parse->line[parse->line_i]) == TRUE)
		{
			if (ft_operator_process(parse) == FAILURE)
				return (FAILURE);
		}
		else
		{
			if (ft_character_process(parse) == FAILURE)
				return (FAILURE);
		}
		parse->line_i++;
		parse->start_i = parse->line_i;
	}
	return (SUCCESS);
}
