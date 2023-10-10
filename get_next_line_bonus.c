/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joan <jocuni-p@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:23:39 by joan              #+#    #+#             */
/*   Updated: 2023/09/04 10:38:27 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	my_free(char **str)
{
	if (*str != NULL && str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

char	*fd_reader(int fd, char *stack)
{
	char	*buff;
	int		bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
	{
		my_free(&stack);
		return (NULL);
	}
	buff[0] = '\0';
	bytes = 1;
	while (bytes > 0 && !(strchr_len(stack, '\n')))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1 || (bytes == 0 && ft_strlen(stack) == 0))
			my_free(&stack);
		if (bytes > 0)
		{
			buff[bytes] = '\0';
			stack = str_join(stack, buff);
		}
	}
	my_free(&buff);
	return (stack);
}

char	*str_extract(char *stack)
{
	char	*line;
	size_t	len;

	len = strchr_len(stack, '\n');
	if (len > 0)
	{
		line = substr(stack, 0, len);
		return (line);
	}
	line = str_join(NULL, stack);
	return (line);
}

char	*clean_stack(char *stack)
{
	char	*new_stack;
	size_t	start;

	start = strchr_len(stack, '\n');
	if (start > 0)
	{
		new_stack = substr(stack, start, ft_strlen(stack));
		my_free(&stack);
		stack = NULL;
		if (ft_strlen(new_stack) == 0)
			my_free(&new_stack);
		return (new_stack);
	}
	return (stack);
}

char	*get_next_line(int fd)
{
	static char	*stack[256] = {NULL};
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		my_free(&stack[fd]);
		return (NULL);
	}
	stack[fd] = fd_reader(fd, stack[fd]);
	if (stack[fd] == NULL)
		return (NULL);
	line = str_extract(stack[fd]);
	if (!strchr_len(line, '\n'))
	{
		my_free(&stack[fd]);
		return (line);
	}
	stack[fd] = clean_stack(stack[fd]);
	return (line);
}
