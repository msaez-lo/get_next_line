/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaez-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:24:02 by msaez-lo          #+#    #+#             */
/*   Updated: 2023/07/15 21:07:25 by msaez-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		i;
	int		j;
	int		len1;
	int		len2;

	len1 = (int)ft_strlen(s1);
	len2 = (int)ft_strlen(s2);
	j = -1;
	i = -1;
	if (!s1 && !s2)
		return (NULL);
	r = (char *)malloc(sizeof(char) * (1 + len1 + len2));
	if (!r)
		return (NULL);
	while (++i != len1)
		r[i] = s1[i];
	while (++j != len2)
		r[i + j] = s2[j];
	r[i + j] = '\0';
	return (r);
}

char	*ft_strtrimlft(const char *s, int c)
{
	int		i;
	int		a;
	char	*ret;

	a = 0;
	i = ft_strchrlen(s, c);
	if (i == -1)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) - i));
	if (!ret)
		return (0);
	i++;
	while (i != (int)ft_strlen(s))
	{
		ret[a] = s[i];
		i++;
		a++;
	}
	ret[a] = '\0';
	return (ret);
}

int	ft_strchrlen(const char *s, int c)
{
	int		a;

	if (s == NULL || ft_strlen(s) == 0)
		return (-1);
	c = (char)c;
	a = 0;
	while (a != (int)ft_strlen(s) && s[a] != c)
		a++;
	if (s[a] == c)
		return (a);
	else
		return (-1);
}

char	*ft_strndup(char *s, int n)
{
	int		i;
	int		a;
	char	*r;

	i = ft_strlen(s);
	if (i == 0)
		return ("");
	if (i > n)
		a = n;
	else
		a = i;
	r = (char *)malloc((a + 1) * sizeof(char));
	if (!r)
		return (NULL);
	i = -1;
	while (++i != a)
	{
		r[i] = s[i];
	}
	r[i] = '\0';
	return (r);
}

size_t	ft_strlen(const char *str)
{
	int		i;
	char	*ret;

	if (str == NULL)
		return (0);
	i = 0;
	ret = (char *)str;
	while (ret[i] != '\0')
		i++;
	return (i);
}
