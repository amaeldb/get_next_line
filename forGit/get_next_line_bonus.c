/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:11:08 by ade-beta          #+#    #+#             */
/*   Updated: 2021/12/14 17:45:55 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*saveret(char **save)
{
	char	*temp;
	char	*ret;

	temp = *save;
	*save = ft_strdup(ft_strchr(*save, '\n') + 1);
	ret = ft_strdup(temp);
	free(temp);
	ret[ft_strlen(ret) - ft_strlen(*save)] = '\0';
	temp = ft_strdup(ret);
	free(ret);
	return (temp);
}

char	*gnlret(int i, char **save)
{
	char	*temp;

	if (ft_strchr(*save, '\n'))
		return (saveret(&*save));
	else if (i == 0 && ft_strlen(*save) > 0)
	{
		temp = ft_strdup(*save);
		free(*save);
		*save = NULL;
		return (temp);
	}
	else
	{
		free(*save);
		*save = NULL;
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*buff;
	int			i;

	i = 1;
	if (fd == 1 || fd == 2 || fd > 1023 || fd < 0)
		return (NULL);
	if (!save[fd])
		save[fd] = (char *)ft_calloc(1, 1);
	buff = (char *)ft_calloc((BUFFER_SIZE + 1), 1);
	if (!save[fd] || !buff)
		return (NULL);
	while (!ft_strchr(save[fd], '\n') && i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 1)
			break ;
		buff[i] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
	}
	free(buff);
	return (gnlret(i, &save[fd]));
}
