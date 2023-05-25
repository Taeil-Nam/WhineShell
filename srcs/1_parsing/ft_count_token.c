/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:28:40 by tnam              #+#    #+#             */
/*   Updated: 2023/05/25 18:06:54 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_pipe_process(t_parse *parse)
{
	if (parse->line[parse->line_i + 1] == '|')
		return (ft_error("Not support '||' symbol in minishell.",
				FAILURE));
	else
		parse->token_count++;
	return (SUCCESS);
}

static int	ft_redirect_process(t_parse *parse)
{
	char	redirect_c;
	int		repeat_count;

	repeat_count = 1;
	redirect_c = parse->line[parse->line_i];
	while (parse->line[parse->line_i + 1] == redirect_c)
	{
		repeat_count++;
		if (repeat_count == 3)
			return (ft_error("Used more than 3 redirection character. \
					(Ex: '<<<...')", FAILURE));
		parse->line_i++;
	}
	parse->token_count++;
	return (SUCCESS);
}

static int	ft_operator_process(t_parse *parse)
{
	if (parse->line[parse->line_i] == '|')
	{
		if (ft_pipe_process(parse) == FAILURE)
			return (FAILURE);
	}
	else if (ft_is_redirect(parse->line[parse->line_i]) == TRUE)
		if (ft_redirect_process(parse) == FAILURE)
			return (FAILURE);
	return (SUCCESS);
}

static int	ft_quote_process(t_parse *parse)
{
	char	end_quote;

	end_quote = parse->line[parse->line_i];
	parse->line_i++;
	while (parse->line[parse->line_i]
		&& parse->line[parse->line_i] != end_quote)
		parse->line_i++;
	if (parse->line[parse->line_i] == '\0')
	{
		ft_printf_err("Quote %c is not closed.\n", end_quote);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_count_token(t_parse *parse)
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
			if (ft_is_quote(parse->line[parse->line_i]) == TRUE)
				if (ft_quote_process(parse) == FAILURE)
					return (FAILURE);
			if (parse->line[parse->line_i + 1] == '\0'
				|| ft_is_space(parse->line[parse->line_i + 1]) == TRUE
				|| ft_is_operator(parse->line[parse->line_i + 1]) == TRUE)
				parse->token_count++;
		}
		parse->line_i++;
	}
	return (SUCCESS);
}
