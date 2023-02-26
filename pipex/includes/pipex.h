/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:19:06 by aleveil           #+#    #+#             */
/*   Updated: 2022/12/15 12:37:46 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

int		main(int argc, char **argv, char **envp);
char	*get_cmd_path(char *cmd, char **envp);
int		exec_cmd(char *input_cmd, char **envp);
void	child1_process(char **argv, int *pipe_fd, char **envp);
void	child2_process(char **argv, int *pipe_fd, char **envp);

void	free_all(char **str);
void	error(void);
void	close_pipe(int *pipe_fd);

#endif