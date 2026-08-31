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

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 10

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*ps2;
	size_t				i;

	i = 0;
	pdest = (unsigned char *)dest;
	ps2 = (const unsigned char *)src;
	while (i < n)
	{
		pdest[i] = ps2[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	final = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!final)
		return (NULL);
	ft_memcpy(final, s1, len1);
	ft_memcpy(final + len1, s2, len2);
	final[len1 + len2] = '\0';
	return (final);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}


char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*final;

	final = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!final)
		return (NULL);
	ft_memcpy(final, s1, ft_strlen(s1));
	ft_memcpy(final + ft_strlen(s1), s2, ft_strlen(s2));
	final[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	free(s2);
	return (final);
}
char	*ft_get_line(char *readline)
{
	char	*returnstring;
	char	*temp;
	char	*start;

	temp = readline;
	while (readline && *readline != '\n')
		readline++;
	returnstring = malloc((readline - temp) + 2);
	if (!returnstring)
		return (NULL);
	start = returnstring;
	while (temp && *temp != '\n')
		*returnstring++ = *temp++;
	if (*temp == '\n')
		*returnstring++ = *temp++;
	*returnstring = '\0';
	return (start);
}

char	*ft_get_temp(char *temp)
{
	char	*start;
	char	*pfree;
	char    *temp2;

	start = temp;
	pfree = temp;
	while (temp && *temp != '\n')
		temp++;
	if (*temp == '\n')
		temp++;
	else
	{
		free(start);
		return NULL;
	}
	start = malloc(ft_strlen(start) + 1);
	temp2 = start;
	if (!start)
		return NULL;
	while (*temp)
		*start++ = *temp++;
	*start = '\0';
    free(pfree);
	return (temp2);
}

char	*ft_read_line(int fd, char *temp)
{
	char	*buf;
	char	*temp2;
	int		i;

	if (!temp)
		temp = malloc(2);
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
	}
	return (temp);
}
char	*get_next_line(int fd)
{
	static char	*temp;
	char		*rtrn;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		return (NULL);
	}
	temp = ft_read_line(fd, temp);
	if (!temp)
		return (NULL);
	rtrn = ft_get_line(temp);
	temp = ft_get_temp(temp);
	return (rtrn);
}

int	main(int argc, char **argv)
{
	char *string;
	int fd;

	fd = open(argv[1], O_RDONLY);
	string = get_next_line(fd);
	printf("%s", string);
	string = get_next_line(fd);

	// printf("%s", string);

	close(fd);
	free(string);
}