/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:23:33 by tnam              #+#    #+#             */
/*   Updated: 2023/04/26 18:39:32 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signal_2(int sig)
{
	(void)sig;
	printf("\n");
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

void	ft_sig_init(void)
{
	struct termios	termios;

	tcgetattr(STDIN_FILENO, &termios);
	termios.c_lflag = ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &termios);
	signal(SIGINT, ft_signal_2);
	signal(SIGQUIT, SIG_IGN);
}
