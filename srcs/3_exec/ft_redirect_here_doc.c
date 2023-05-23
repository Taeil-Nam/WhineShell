/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_here_doc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:07:24 by tnam              #+#    #+#             */
/*   Updated: 2023/05/23 14:23:21 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_here_doc_get_input(t_redirect *redirect)
{
	char	*input;
	char	*limiter;
	int		temp_fd;

	temp_fd = open("/tmp/whine", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644);
	if (temp_fd == FAILURE)
		exit (ft_perror(errno));
	limiter = ft_strjoin(redirect->value, "\n");
	if (limiter == NULL)
		exit (ft_error("limiter malloc failed.", 1));
	while (TRUE)
	{
		write(1, "> \0", 3);
		input = get_next_line(STDIN_FILENO);
		if (!input || ft_strncmp(input, limiter, ft_strlen(limiter)) == 0)
			break ;
		write(temp_fd, input, ft_strlen(input));
		free(input);
	}
	free(input);
	free(limiter);
	if (close(temp_fd) == FAILURE)
		exit(ft_perror(errno));
}

void	ft_redirect_here_doc(t_exec_info *exec_info, t_redirect *redirect)
{
	ft_here_doc_get_input(redirect);
	exec_info->infile_fd = open("/tmp/whine", O_RDONLY);
	if (exec_info->infile_fd == FAILURE)
		exit (ft_perror(errno));
	if (dup2(exec_info->infile_fd, STDIN_FILENO) == FAILURE)
		exit (ft_perror(errno));
	if (close(exec_info->infile_fd) == FAILURE)
		exit (ft_perror(errno));
}
