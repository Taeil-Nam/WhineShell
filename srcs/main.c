/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:30:14 by tnam              #+#    #+#             */
/*   Updated: 2023/04/18 21:53:53 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	leak(void)
{
	system("leaks -q $PPID");
}

void	ft_print_list(t_list *list)
{
	list->cur_node = list->front_node;
	while (list->cur_node)
	{
		printf("%s\n", (char *)(list->cur_node->content));
		list->cur_node = list->cur_node->next_node;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_info	info;
	t_parse	parse;
	
	//atexit(leak);
	info.mini_envp = ft_list_init();
	ft_mini_envp_init(envp, &(info.mini_envp));
	char *a = readline("whine 🍷");
	if (strcmp(a, "env") == 0)
		ft_print_list(&(info.mini_envp));
	free(a);
	a = readline("whine 🍷");
	printf("%s\n", a);
	free(a);
	ft_list_clear(&(info.mini_envp));

	return (EXIT_SUCCESS);
}
