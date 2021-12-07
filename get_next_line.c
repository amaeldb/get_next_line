/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:10:07 by ade-beta          #+#    #+#             */
/*   Updated: 2021/12/07 16:04:59 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*saveret(char **save)
{
	char	*str;
	char	*str2;

	str = "Shalom";
	str = ft_strdup(*save);
	//str = ft_strcpy(str, (char *)*save);
	*save = ft_strchr(*save, '\n') + 1;
	str[ft_strlen(str) - ft_strlen(*save)] = '\0';
	//str = ft_strcpy(str, str);
	str2 = ft_strdup(str);
	free(str);
	return (str2);
}

char	*lineret(char *buff, char **save)
{
	*save = ft_strchr(*save, '\n') + 1;
	buff[ft_strlen(buff) - ft_strlen(*save)] = '\0';
	buff = ft_strdup(buff);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*save[2048];
	char		*buff;
	int			val;

	if(fd > 2048 || fd == 1 || fd == 2)
		return (NULL);
	if(ft_strchr(save[fd], '\n'))
		return (saveret(&save[fd]));
	val = 1;
	while (val)
	{
		val = read(fd, buff, BUFFER_SIZE);
		if (ft_strchr(buff, '\n'))
			return (lineret(buff, &save[fd]));
	}
	return (NULL);
}

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	static char	*str = "Malloc\nma\nballs";
	char *ret = "MALLOC\nMA\nBALLS";
	char *ret2;
	ret = ft_strdup(str);
	ret2 = lineret(ret, &str);
	printf("ret = %s.\n", ret2);
	free(ret);
	//printf("%s\n", str);
	ret = saveret(&str);
	printf("ret = %s.\n", ret);
 	//printf("%s\n", str);
	free(ret2);
	free(ret);
}
