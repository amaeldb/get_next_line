/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:43:25 by ade-beta          #+#    #+#             */
/*   Updated: 2021/12/09 13:53:25 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	ret = ft_strdup(dest);
	free(dest);
	return (ret);
}

char	*ft_strchr(const char *s, int c)
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

char	*ft_strdup(const char *src)
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
