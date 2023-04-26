/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:30:14 by tnam              #+#    #+#             */
/*   Updated: 2023/04/26 18:04:32 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_parse_execute(t_minishell *mini, t_info *info, t_parse *parse)
{
	if (ft_parse(mini, info, parse) == FAILURE)
		return ;
	/* if (ft_execute(mini, info, parse) == FAILURE)
		return ; */
}

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	mini;
	t_info		info;
	t_parse		parse;

	mini.info = &info;
	mini.parse = &parse;
	ft_init(argc, argv, envp, &mini);
	while (TRUE)
	{
		parse.line = readline("whine 🍷 ");
		if (parse.line == NULL)
		{
			printf("exit\n");
			return (EXIT_SUCCESS);
		}
		add_history(parse.line);
		ft_parse_execute(&mini, &info, &parse);
		printf("token count : %zu\n", parse.token_count); //test
		free(parse.line);
	}
	return (EXIT_SUCCESS);
}
