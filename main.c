#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	file_descriptor;
	char	*line;

	if (argc < 2)
	{
		printf("File name missing.");
		return (1);
	}
	if (argc > 2)
	{
		printf("Too many arguments");
		return (1);
	}
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		printf("Error opening file.");
		return (1);
	}
	while ((line = get_next_line(file_descriptor)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}