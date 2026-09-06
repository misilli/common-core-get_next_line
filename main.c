/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumidill <mumidill@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:09:29 by mumidill          #+#    #+#             */
/*   Updated: 2026/09/06 16:11:52 by mumidill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line.h"

/*int	main(int argc, char **argv)
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