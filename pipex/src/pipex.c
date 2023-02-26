/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:01:26 by aleveil           #+#    #+#             */
/*   Updated: 2022/12/15 12:44:57 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**all_paths;
	int		i;
	char	*path;
	char	*path_slash;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	all_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (all_paths[i++])
	{
		path_slash = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(path_slash, cmd);
		free(path_slash);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	free_all(all_paths);
	return (0);
}

int	exec_cmd(char *input_cmd, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(input_cmd, ' ');
	if (access(cmd[0], F_OK) == -1)
	{
		if (!envp[0])
			path = NULL;
		else
			path = get_cmd_path(cmd[0], envp);
		if (!path)
		{
			free(cmd);
			error();
		}
	}
	else
		path = cmd[0];
	if (execve(path, cmd, envp) == -1)
	{
		return (-1);
	}
	return (0);
}

void	child1_process(char **argv, int *pipe_fd, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		error();
	dup2(infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	if (exec_cmd(argv[2], envp) == -1)
	{
		close(infile);
		error();
	}
}

void	child2_process(char **argv, int *pipe_fd, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (outfile == -1)
		error();
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipe_fd[1]);
	if (exec_cmd(argv[3], envp) == -1)
	{
		close(outfile);
		error();
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid_child1;
	pid_t	pid_child2;

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			error();
		pid_child1 = fork();
		if (pid_child1 == -1)
			error();
		if (pid_child1 == 0)
			child1_process(argv, pipe_fd, envp);
		waitpid(pid_child1, NULL, 0);
		pid_child2 = fork();
		if (pid_child2 == -1)
			error();
		if (pid_child2 == 0)
			child2_process(argv, pipe_fd, envp);
		close_pipe(pipe_fd);
		waitpid(pid_child2, NULL, 0);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
