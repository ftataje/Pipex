/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:08:52 by ftataje-          #+#    #+#             */
/*   Updated: 2022/09/26 16:58:56 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_pros(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		error();
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	exemy(argv[2], envp);
}

void	parent_pros(char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (outfile == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	exemy(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_pros(argv, envp, fd);
		waitpid(pid1, NULL, 0);
		parent_pros(argv, envp, fd);
	}
	else
	{
		error();
	}
}
