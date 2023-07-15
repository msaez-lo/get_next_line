/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaez-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:23:55 by msaez-lo          #+#    #+#             */
/*   Updated: 2023/07/15 20:59:13 by msaez-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*until_n(int fd, char *var);
char	*clean(char *ret, char **auxch, char **var);
char	*ln_in_var(char *var, int a);
char	*fun_var(char *var);
char	*ft_strdup(const char *s1);
int		ft_strchrlen(const char *s, int c);
char	*ft_strndup(char *s, int n);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrimlft(const char *s, int c);
char	*save_lines(char *buf, char *ret, int i, char *auxch);
#endif
