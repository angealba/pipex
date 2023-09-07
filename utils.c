/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:16:46 by analbarr          #+#    #+#             */
/*   Updated: 2023/06/09 17:17:08 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	msg(char *error)
{
	write(2, error, ft_strlen(error));
	return (1);
}

int	error_exit(char *error)
{
	perror(error);
	exit (1);
}

void	free_parent(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->in_fd);
	close(pipex->out_fd);
	while(pipex->cmd_paths[i])
		free(pipex->cmd_paths[i++]);
	free(pipex->cmd_paths);
}