/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:23:33 by tnam              #+#    #+#             */
/*   Updated: 2023/05/29 15:26:06 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signal_2(int sig)
{
	(void)sig;
	g_child_exit_code = 1;
	printf("\n");
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

void	ft_sig_init(t_info *info)
{
	info->termios = info->termios_backup;
	info->termios.c_lflag = ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &info->termios);
	signal(SIGINT, ft_signal_2);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_sig_for_here_doc_parent(int sig)
{
	(void)sig;
	printf("\n");
}

void	ft_sig_for_here_doc_child(int sig)
{
	(void)sig;
	exit(1);
}

void	ft_sig_for_parent(int sig)
{
	if (sig == SIGINT)
	{
		printf("^C\n");
	}
	if (sig == SIGQUIT)
	{
		printf("^\\Quit: %d\n", sig);
	}
}
