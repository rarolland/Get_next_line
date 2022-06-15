#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*ligne;
	int		size_read;
	
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	ligne = NULL;
	ligne = ft_strjoin(ligne, buffer);
	size_read = BUFFER_SIZE;
	while (!(end_line(ligne) || size_read != BUFFER_SIZE)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read < 0)
			return (NULL);
		buffer[size_read] = '\0';
		ligne = ft_strjoin(ligne, buffer);
	}
	if (!ligne[0])
	{
		free(ligne);
		return (NULL);
	}
	else
		get_line(ligne, buffer);
	return (ligne);
}
