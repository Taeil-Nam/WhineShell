/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:30:14 by tnam              #+#    #+#             */
/*   Updated: 2023/06/02 09:04:35 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_parse_execute(t_info *info, t_parse *parse, t_exec *exec)
{
	if (ft_parse(info, parse) == FAILURE)
		return ;
	if (ft_make_exec_info(info, parse, exec) == FAILURE)
		return ;
	if (ft_exec(info, parse, exec) == FAILURE)
		return ;
	ft_free_all(parse, exec);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_info		info;
	t_parse		parse;
	t_exec		exec;

	ft_init(argc, argv, envp, &info);
	while (TRUE)
	{
		ft_sig_init(&info);
		parse.line = readline("\033[0;35mwhine 🍷 ");
		if (parse.line == NULL)
		{
			ft_list_clear(&info.mini_envp);
			ft_putstr_fd("\x1b[1A\033[9Cexit\n", STDOUT_FILENO);
			return (EXIT_SUCCESS);
		}
		if (parse.line[0] == '\0')
		{
			free(parse.line);
			continue ;
		}
		add_history(parse.line);
		ft_parse_execute(&info, &parse, &exec);
		free(parse.line);
	}
	return (EXIT_SUCCESS);
}
