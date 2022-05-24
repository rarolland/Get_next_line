#include "get_next_line.h"

char *ft_select(char *buf, int *ret)
{
	int i;
	char *dest;

	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
		i++;
	dest = malloc(i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	if (ft_strchr(buf, '\n') != 0)
		*ret = 1;
	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
	{
		dest[i] = buf[i];
		i++;
	}
	dest[i] = 0;
	return (0);
}

char *ft_select2(char *buf)
{
	int	i;
	int	j;
	char *dest;
	
	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
		i++;
	dest = malloc(sizeof(*dest) + (ft_strlen(buf) - i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (buf && buf[i])
		dest[j++] = buf[++i];
	dest[j] = 0;
	return (dest);
}