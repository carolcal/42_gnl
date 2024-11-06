/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:28:05 by cayamash          #+#    #+#             */
/*   Updated: 2024/11/04 19:30:31 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

//size_t	fill_with_rest(int fd, char *line, char *rest);
void	*read_buffer_size(int fd, void *buffer);

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	*rest;
// 	size_t		end_line;

// 	if (ft_strlen(rest))
// 	{
// 		end_line = fill_with_rest(fd, line, rest);
// 		if (end_line)
// 			return (line);
// 	}
// 	read_line(fd, line, rest);
// }

/*if there is a rest it fills line with rest till \n 
or till the end of rest
in rest_line1 line_len gets length till \n or \0
in rest_line2 strlen gets length till \0
if rest_line2 > rest_line1, there a \n in the middle of rest
so it reatributes rest the rest of the chars
returns 1 if there is a \n in rest, 
meaning that the line reached its end
returns 0 if there is not \n in rest,
meaning it has to continue to call read_line*/
// size_t	fill_with_rest(int fd, char *line, char *rest)
// {
// 	size_t	rest_len1;
// 	size_t	rest_len2;
// 	void	*buffer;

// 	rest_len1 = line_len(rest);
// 	rest_len2 = strlen(rest);
// 	if (rest_len1 > 0)
// 		ft_strlcpy(line, rest, rest_len1);
// 	if (rest_len2 > rest_len1)
// 		rest = substr(rest, rest_len1, rest_len2);
// 	if (line[rest_len1] == '\n')
// 		return (1);
// 	return (0);
// }

	// 1) call read_buffer_size
	// 2) search for \n in buffer
	// 3) if \n
	// 	a)concat line with buffer till \n 
	// 	b)atribute chars after \n to rest
	// 	c) return
	// 4) else call step1
//make this function recursive and use struct
void	read_line(int fd, unsigned char **line, unsigned char **rest)
{
	void	*buffer;
	//char	*sub;

	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	buffer = read_buffer_size(fd, buffer);
	if (buffer)
	{
		*rest = ft_strchr(buffer, '\n') + 1;
		*line = (unsigned char *)buffer;
	}
}

#include <stdio.h>

void	*read_buffer_size(int fd, void *buffer)
{
	ssize_t	resp;
	
	resp = read(fd, buffer, BUFFER_SIZE);
	if (resp > 0)
		return (buffer);
	else
		return (NULL);
}

#include <fcntl.h>
int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int fd;
		unsigned char *line = NULL;
		unsigned char *rest = NULL;


		fd = open(argv[1], O_RDONLY);
		if (fd != -1)
		{
			read_line(fd, &line, &rest);
			write(1, "line: ", 6);
			write(1, line, BUFFER_SIZE);
			write(1, "\nrest: ", 7);
			write(1, rest, BUFFER_SIZE);
		}
	}
	return (0);
}
