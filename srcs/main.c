/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:30:14 by tnam              #+#    #+#             */
/*   Updated: 2023/04/18 17:47:15 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	leak(void)
{
	system("leaks -q $PPID");
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;

	atexit(leak);

	line = readline("Input string : ");
	printf("%s\n", line);
	free(line);

	return (EXIT_SUCCESS);
}
