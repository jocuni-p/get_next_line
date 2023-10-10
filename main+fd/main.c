/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:43:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/08/29 12:39:21 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int 	i = 9;
    int     buffer;
	char 	*line;

    buffer = BUFFER_SIZE;
	fd = open("./file_to_read_6.txt", O_RDONLY);
    printf("====================================\n");
	printf("fd = %i\n", fd);
    printf("llamadas a 'get_next_line' = %i\n", i);
    printf("BUFFER_SIZE = %i\n", buffer);
    printf("====================================\n");
	while(i > 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			printf("%s Nada que leer / Error\n", line);
			i--;
		}
		else
		{
			printf("%s", line);
			usleep (300000);
			i--;
			my_free(&line);
		}
	}
	close(fd);
	return (0);
}
