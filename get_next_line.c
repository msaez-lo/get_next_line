/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaez-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:23:42 by msaez-lo          #+#    #+#             */
/*   Updated: 2023/07/15 20:53:10 by msaez-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_lines(char *buf, char *ret, int i, char *auxch)
{
	if (i == 0 || i == -1)
	{
		free(buf);
		return (0);
	}
	buf[i] = '\0';
	ret = ft_strjoin(ret, buf);
	if (!ret)
	{
		free(buf);
		return (0);
	}
	free(buf);
	if (auxch[0])
		free(auxch);
	return (ret);
}

char	*until_n(int fd, char *var)
{
	char	*auxch;
	char	*ret;
	char	*buf;
	int		i;

	i = BUFFER_SIZE;
	ret = ft_strndup(var, ft_strlen(var));
	if (!ret)
		return (0);
	auxch = ret;
	while (ft_strchrlen(ret, '\n') == -1 && i == BUFFER_SIZE)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (0);
		i = read(fd, buf, BUFFER_SIZE);
		if (i == 0 && ret[0])
		{
			free(buf);
			return (ret);
		}
		ret = save_lines(buf, ret, i, auxch);
		auxch = ret;
	}
	return (ret);
}

char	*clean(char *ret, char **auxch, char **var)
{
	char	*r;
	int		i;

	*auxch = *var;
	*var = ln_in_var(ret, -1);//MALLOC SIN PROTEGER
	if (*auxch[0])
		free(*auxch);
	*auxch = ret;
	i = 0;
	if (ft_strchrlen(ret, '\n') == -1)
	{
		r = ft_strndup(ret, (int)ft_strlen(ret));
		return (r);
	}
	r = (char *)malloc(sizeof(char) * (ft_strchrlen(ret, '\n') + 2));
	if (!r)
		return (0);
	while (i != ft_strchrlen(ret, '\n'))
	{
		r[i] = ret[i];
		i++;
	}
	r[i] = '\n';
	r[i + 1] = '\0';
	return (r);
}

char	*ln_in_var(char *var, int a)
{
	char	*auxch;

	if (a != -1)
	{
		auxch = var;
		if (a + 1 == (int)ft_strlen(var))
			var = NULL;
		else
		{
			var = ft_strtrimlft(var, '\n');
			if (!var)
			{
				free(auxch);
				return (0);
			}
		}
		free(auxch);
		return (var);
	}
	if (ft_strchrlen(var, '\n') == -1
		|| ft_strchrlen(var, '\n') + 1 == (int)ft_strlen(var))
		return (NULL);
	else
		return (ft_strtrimlft(var, '\n'));
}

char	*get_next_line(int fd)
{
	char		*ret;
	char		*auxch;
	static char	*var;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4096)
		return (0);
	if (!var)
		var = "";
	if (ft_strchrlen(var, '\n') != -1)
	{
		ret = ft_strndup(var, ft_strchrlen(var, '\n') + 1);
		if (!ret)
			return (0);
		var = ln_in_var(var, ft_strchrlen(var, '\n')); //MALLOC SIN PROTEGER;
		return (ret);
	}
	ret = until_n(fd, var);
	if (!ret)
		return (0);
	auxch = var;
	ret = clean(ret, &auxch, &var);
	if (!ret)
		return (0);
	free(auxch);
	return (ret);
}
