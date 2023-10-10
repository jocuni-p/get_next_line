/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:29:33 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/08/24 11:06:25 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line(int fd);
char	*fd_reader(int fd, char *stack);
char	*str_extract(char *stack);
char	*clean_stack(char *stack);
void	my_free(char **str);
size_t	ft_strlen(char *s);
size_t	strchr_len(char *s, char c);
char	*str_join(char *s1, char *s2);
char	*substr(char *stack, unsigned int start, size_t len);

#endif
