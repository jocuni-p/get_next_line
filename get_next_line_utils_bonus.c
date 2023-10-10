/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:02:24 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/08/24 16:53:25 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	strchr_len(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*str_join(char *s1, char *s2)
{
	ssize_t	i;
	size_t	j;
	char	*join;

	if (!s1 && !s2)
		return (NULL);
	join = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!join)
	{
		my_free(&s1);
		return (NULL);
	}
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		join[i++] = s2[j++];
	join[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	my_free(&s1);
	return (join);
}

char	*substr(char *stack, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!stack)
		return (NULL);
	sub = (char *) malloc(sizeof(char) * (len - start + 1));
	if (!sub)
		return (NULL);
	while (stack[start + i] && i < len)
	{
		sub[i] = stack[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
