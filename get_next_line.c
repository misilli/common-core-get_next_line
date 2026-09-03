/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumidill <mumidill@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 19:55:27 by mumidill          #+#    #+#             */
/*   Updated: 2026/08/30 20:21:06 by mumidill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 10

char	*ft_get_rtrn(char *temp)
{
	char	*rtrn;

	rtrn = malloc((ft_strchrnul(temp, '\n') - temp) + 2);
	if (!rtrn)
		return (NULL);
	ft_strlcpy(rtrn, temp, (ft_strchrnul(temp, '\n') - temp) + 2);
	return (rtrn);
}

char	*ft_get_temp(char *temp)
{
	char	*rtrn;
	char	*head;

	head = temp;
	temp = ft_strchrnul(temp, '\n');
	if (*temp == '\n')
	{
		rtrn = malloc(ft_strlen(temp + 1) + 1);
		if (!rtrn)
		{
			free(head);
			return (NULL);
		}
		ft_strlcpy(rtrn, temp + 1, ft_strlen(temp + 1) + 1);
		free(head);
		return (rtrn);
	}
	free(head);
	return (NULL);
}

char	*ft_read_line(int fd, char *temp)
{
	char	*buf;
	int		i;

	if (!temp)
	{
		temp = malloc(1);
		if (!temp)
			return (NULL);
		*temp = '\0';
	}
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(temp, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i <= 0)
			break ;
		buf[i] = '\0';
		temp = ft_strjoinfree(temp, buf);
		if (!temp)
			return (NULL);
	}
	free(buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*rtrn;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	temp = ft_read_line(fd, temp);
	if (!temp)
		return (NULL);
	if (*temp == '\0')
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	rtrn = ft_get_rtrn(temp);
	temp = ft_get_temp(temp);
	return (rtrn);
}
