/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:51:41 by analbarr          #+#    #+#             */
/*   Updated: 2023/06/09 16:52:04 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	msg(char *error)
{
	write(2, error, ft_strlen(error));
	return (1);
}

int	error_msg(char *error)
{
	perror(error);
	exit (1);
}

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4) != 0)
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc != 5)
		return (msg("Error in number of arguments."));
	pipex->in_fd = open(argv[1], O_RDONLY);
	if (pipex->in_fd < 0)
		error_msg("Infile error.\n");
	pipex->out_fd = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0777);
	if (out_fd < 0)
		error_msg("Outfile error.\n");
	if (pipe(pipex->tube) < 0)
		error_msg("Pipe error.\n");
	pipex->path = find_path(envp);
	pipex->cmd_paths = ft_split(pipex->path, ':');
	


	




}