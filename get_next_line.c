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

char	*get_next_line(int fd)
{
	size_t	i;
	char	*s1;
	char	*rtrn;
	char	*temp;

	rtrn = malloc(1);
	rtrn[0] = '\0';
	s1 = malloc(6);
	while (!(ft_strchr(s1, '\n')))
	{
		i = read(fd, s1, 5);
		if (i <= 0)
			break ;
		s1[i] = '\0';
		temp = rtrn;
		rtrn = ft_strjoin(rtrn, s1);
		free(temp);
	}
	free(s1);
	return (rtrn);
}

int	main(int argc, char **argv)
{
	char *string;
	int fd;

	fd = open(argv[1], O_RDONLY);
	string = get_next_line(fd);

	close(fd);

	printf("%s", string);
	free(string);
}