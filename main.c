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

<<<<<<< HEAD
int	main(int argc, char **argv)
=======
/*size_t	ft_strlen(const char *s)
>>>>>>> 2b4292be1b26d15e45ff92bc47620b7c3095b6b2
{
	argc = argc;
	char	*line;
	int fd = open(argv[1],O_RDONLY);

	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}

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