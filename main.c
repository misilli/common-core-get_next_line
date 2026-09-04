/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumidill <mumidill@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:09:29 by mumidill          #+#    #+#             */
/*   Updated: 2026/09/04 19:02:01 by mumidill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line.h"

/*size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (i + 1 < size && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (size != 0)
	{
		dest[i] = '\0';
	}
	while (src[j])
	{
		j++;
	}
	return (j);
}
char	*ft_strchrnul(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return ((char *)s);
}
char	*ft_get_line(char *readline)
{
	char	*returnstring;

	returnstring = malloc((ft_strchrnul(readline, '\n') - readline) + 2);
	if (!returnstring)
		return (NULL);
	ft_strlcpy(returnstring, readline, ft_strchrnul(readline, '\n') - readline
		+ 2);
	return (returnstring);
}
char	*ft_get_temp(char *temp)
{
	char	*start;
	char	*head;

	head = temp;
	temp = ft_strchrnul(temp, '\n');
	if (*temp == '\n')
	{
		start = malloc(ft_strlen(temp + 1) + 1);
		if (!start)
		{
			free(head);
			return (NULL);
		}
		ft_strlcpy(start, temp + 1, ft_strlen(temp +1) + 1);
		free(head);
		return (start);
	}
	free(head);
	return (NULL);
}

int	main(void)
{
	char	a[100] = "1\n2\0";
	char	*pa;
	char	*line;

	pa = strdup(a);
	line = ft_get_temp(pa);
	printf("%s", line);
	return (0);
}*/
int	main(int argc ,char **argv)
{
	int fd = open(argv[1],O_RDONLY);
	char *string = get_next_line(fd);
	argc =argc;
	printf("%s",string);	
	while (string != NULL)
	{
		printf("%s",string);
		free(string);
		string = get_next_line(fd);
	}
	return(0);
}