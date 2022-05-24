#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	char	*temp;

	news = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!news)
		return (NULL);
	temp = news;
	while (*s1)
		*news++ = *s1++;
	while (*s2)
		*news++ = *s2++;
	*news = 0;
	return (temp);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *get_next_line(int fd)
{
    char        buf[BUFFER_SIZE + 1];
    int         ret;
    static char *str = NULL;
    char        *temp;
    char        **ligne;

    ret = BUFFER_SIZE;
    if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
        return (-1);
    while (ret > 0)
    {
        ret = read(fd, buf, BUFFER_SIZE);
        if (ret == -1)
            return (-1);
        temp = str;
        buf[ret] = 0;
        str = ft_strjoin(temp, buf);
        free(temp);
        if (ft_strchr(str, '\n'))
            break;
            // Coucou comment vas tu ? \ndiued
    }
    *ligne = ft_select(str, &ret);
    temp = str;
    str = ft_select2(str);
    free(temp);
     //if (ret == 0 && (*str) == 0)
     // {
     //   free(str);
     // *str = NULL;
     // }
    return (ret);
}
