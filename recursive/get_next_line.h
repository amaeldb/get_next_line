/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:38:39 by ade-beta          #+#    #+#             */
/*   Updated: 2021/12/09 12:43:16 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif


#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
char	*ft_strcat(char *dest, char *src);

#endif
