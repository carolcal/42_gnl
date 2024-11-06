/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:28:05 by cayamash          #+#    #+#             */
/*   Updated: 2024/11/06 19:55:24 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

char	*read_line(int fd);
char	*get_rest(char *line);
size_t	fill_with_rest(char *line, char **rest);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;
	size_t		end_line;

	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (rest && ft_strlen(rest))
	{
		end_line = fill_with_rest(line, &rest);
		if (end_line)
			return (line);
	}
	line = read_line(fd);
	rest = get_rest(line);
	// write(1, "\nline: ", 6);
	// write(1, line, ft_strlen(line)+1);
	// write(1, "\nrest: ", 7);
	// write(1, rest, BUFFER_SIZE);
	return (line);
}

size_t	fill_with_rest(char *line, char **rest)
{
	size_t	i;
	size_t	rest_len;
	char	*new_rest;

	i = 0;
	rest_len = ft_strlen(*rest);
	while ((*rest)[i] != '\n' && i < rest_len)
	{
		line[i] = (*rest)[i];
		i++;
	}
	if ((*rest)[i] == '\n')
	{
		line[i] = (*rest)[i];
		i++;
	}
	line[i] = '\0';
	if (i < rest_len)
	{
		new_rest = ft_substr(*rest, i, rest_len - i);
		free(rest);
		*rest = new_rest;
		return (1);
	}
	else
	{
		free(*rest);
        *rest = NULL;
		return (0);
	}
}

char	*read_line(int fd)
{
	char	*buffer;
	ssize_t	buff_size;
	char	*sub;
	char	*temp;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buff_size = 1;
	sub = ft_strdup("");
	while (buff_size > 0)
	{
		buff_size = read(fd, buffer, BUFFER_SIZE);
		buffer[buff_size] = '\0';
		temp = sub;
        sub = ft_strjoin(sub, buffer);
        free(temp);
        if (ft_strchr(buffer, '\n'))
            break;
	}
	free(buffer);
	return (sub);
}

char	*get_rest(char *line)
{
	int	linelen;
	int	restlen;
	char	*rest;

	linelen = 0;
	while (line[linelen] != '\n' && line[linelen] != '\0')
		linelen++;
	if (line[linelen] == '\n')
        linelen++;
	restlen = ft_strlen(line) - linelen;
	if (restlen > 0)
	{
		rest = ft_substr(line, linelen, restlen);
		line[linelen] = '\0';
	}
	else
		rest = NULL;
	return (rest);
}

#include <fcntl.h>
int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int fd;
		char	*line;

		fd = open(argv[1], O_RDONLY);
		if (fd != -1)
		{
			line = get_next_line(fd);
			printf("%s\n", line);
			free(line);
			line = get_next_line(fd);
			printf("%s\n", line);
			free(line);
		}
	}
	return (0);
}
