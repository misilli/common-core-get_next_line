/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumidill <mumidill@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:54:12 by mumidill          #+#    #+#             */
/*   Updated: 2026/09/02 16:54:12 by mumidill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*rtrn;

	rtrn = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rtrn)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	ft_strlcpy(rtrn, s1, ft_strlen(s1) + 1);
	ft_strlcpy(rtrn + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (rtrn);
}
