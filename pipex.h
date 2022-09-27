/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:18:05 by ftataje-          #+#    #+#             */
/*   Updated: 2022/09/26 17:17:34 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

void	error(void);
char	*path2(char *cmd, char **envp);
void	exemy(char *argv, char **envp);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		get_next_line(char **line);
int		open_file(char *argv, int i);

#endif