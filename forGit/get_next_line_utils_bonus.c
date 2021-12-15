/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:29:33 by ade-beta          #+#    #+#             */
/*   Updated: 2021/12/15 14:29:39 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*ret;

	i = -1;
	ret = (char *)s;
	while (ret[++i])
		if (ret[i] == (char)c)
			return (&ret[i]);
	if (!c)
		return (&ret[i]);
	return (NULL);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = 0;
	while (src[i])
		i++;
	str = malloc(i + 1);
	if (!str)
		return (0);
	i = 0;
	while (src[i])
	{
		str[i] = (char)src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	while (s1[++i])
		ret[i] = (char)s1[i];
	i = -1;
	while (s2[++i])
		ret[ft_strlen(s1) + i] = (char)s2[i];
	ret[i + ft_strlen(s1)] = '\0';
	free(s1);
	return (ret);
}

void	*ft_calloc(int nmemb, int size)
{
	unsigned char	*ret;
	int				i;

	ret = malloc(size * nmemb);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < nmemb)
	{
		ret[i] = 0;
		i++;
	}
	return (ret);
}
