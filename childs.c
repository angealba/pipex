/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:42:13 by analbarr          #+#    #+#             */
/*   Updated: 2023/07/24 17:42:56 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	get_cmd_line(char **paths, char *cmd)
{
	char	tmp;
	char	command;

	while(*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if(access(command, F_OK | X_OK) == 0)
			return(command);
		free(command);
		paths++;
	}
	return(NULL);
}

void	child_one(t_pipex pipex, char **av, char **envp)
{
	int	i;

	i = 0;
	dup2(pipex->tube[1], STDOUT_FILENO);
	dup2(pipex->in_fd, STDIN_FILENO);
	close(pipex->tube[0]);
	pipex->cmd_args = ft_split(av[2], ' ');
	pipex->cmd = get_cmd_line(pipex->cmd_paths, pipex->cmd_args[0]);
	if(!pipex->cmd)
	{
		while(pipex->cmd_args[i])
			free(pipex->cmd_args[i++]);
		free(pipex->cmd_args);
		free(pipex->cmd);
		error_exit("Error in command\n");
	}
	execve(pipex->cmd, pipex->cmd_args, envp);
}

void	child_two(t_pipex pipex, char **av, char **envp)
{
	int	i;

	i = 0;
	dup2(pipex->tube[0], STDIN_FILENO);
	dup2(pipex->out_fd, STDOUT_FILENO);
	close(pipex->tube[1]);
	pipex->cmd_args = ft_split(av[3], ' ');
	pipex->cmd = get_cmd_line(pipex->cmd_paths, pipex->cmd_args[0]);
	if(!pipex->cmd)
	{
		while(pipex->cmd_args[i])
			free(pipex->cmd_args[i++]);
		free(pipex->cmd_args);
		free(pipex->cmd);
		error_exit("Error in command\n");
	}
	execve(pipex->cmd, pipex->cmd_args, envp);
}

