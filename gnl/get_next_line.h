/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 00:41:01 by aleveil           #+#    #+#             */
/*   Updated: 2022/03/03 02:21:08 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *s);
char	*ft_strndup(char *s, int n);
int		ft_strichr(char *s, int c);
char	*ft_join(char *s1, char *s2);
void	ft_get_line(char **buf, char **line);
int		ft_read(int fd, char **s_buf, char **buf, char **line);
char	*get_next_line(int fd);

#endif
