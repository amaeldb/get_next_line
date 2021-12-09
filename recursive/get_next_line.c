/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:10:07 by ade-beta          #+#    #+#             */
/*   Updated: 2021/12/09 14:35:34 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*saveret(char **save)
{
	char	*str;
	char	*str2;

	str = ft_strdup(*save);
	*save = ft_strchr(*save, '\n') + 1;
	str[ft_strlen(str) - ft_strlen(*save)] = '\0';
	str2 = ft_strdup(str);
	free(str);
	return (str2);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*buff;
	int			val;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!save[fd])
	{
		save[fd] = (char *)malloc(BUFFER_SIZE + 1);
		save[fd][0] = '\0';
	}
	if(fd > 1024 || fd == 1 || fd == 2 || fd < 0)
		return (NULL);
	if(ft_strchr(save[fd], '\n'))
		return (saveret(&save[fd]));
	val = read(fd, buff, BUFFER_SIZE);
	if(val <= 0)
	{
		free(buff);
		return (NULL);
	}
	buff[val] = '\0';
	save[fd] = ft_strcat(save[fd], buff);
	free(buff);
	if((val && val > 0) || ft_strchr(save[fd], '\n'))
		return (get_next_line(fd));
	return (save[fd]);
}
/*
int main(void)
{
	int fd;
	char *ret;

	fd = open("test.txt", O_RDWR);
	while (ret = get_next_line(fd))
		printf("%s", ret);
}*/
