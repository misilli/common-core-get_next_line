/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumidill <mumidill@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:09:29 by mumidill          #+#    #+#             */
/*   Updated: 2026/08/30 17:43:50 by mumidill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
	free(temp - (returnstring - start));
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

int	main(void)
{
	char a[100]= "Hello, World!\nThis is a test string";
	char *pa;
	pa = strdup(a);
	
	char *line;
	line = ft_get_line(pa);
	printf("%s", line);
	return (0);
}