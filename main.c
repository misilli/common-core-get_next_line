/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumidill <mumidill@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:09:29 by mumidill          #+#    #+#             */
/*   Updated: 2026/08/30 17:09:29 by mumidill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = strlen(s1);
	len2 = strlen(s2);
	final = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!final)
		return (NULL);
	memmove(final, s1, len1);
	memmove(final + len1, s2, len2);
	final[len1 + len2] = '\0';
	return (final);
}

int	main(void)
{
	char *a;
    char *cevap;


	a = malloc(8);
	int fd = open("deneme.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while (!(strchr(a,'\n')))
	{
		size_t len = read(fd, a, 6);
		a[len] = '\0';
		//printf("%s%c", a, *(a + 6) + '0');
        
        cevap = ft_strjoin(cevap , a);
	}
    printf("\n%s",cevap);
	close(fd);
	return (0);
}