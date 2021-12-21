#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	ft_check_endl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		str[i++] = '\n';
	else
		str[i++] = '\0';
	str[i] = '\0';
	return (str);
}

char	*ft_new_static_str(char *s)
{
	int		i;
	int		j;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(s) - i + 2);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	free(s);
	return (str);
}

char	*ft_read_static_str(int fd, char *sstr)
{
	char	*buff;
	int		read_check;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_check = -1;
	while (!ft_check_endl(sstr) && read_check)
	{
		read_check = read(fd, buff, BUFFER_SIZE);
		if (read_check == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[read_check] = '\0';
		sstr = ft_strjoin(sstr, buff);
	}
	free(buff);
	return (sstr);
}

char	*get_next_line(int fd)
{
	static char	*sstr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sstr = ft_read_static_str(fd, sstr);
	if (!sstr)
		return (NULL);
	line = ft_get_line(sstr);
	if (!ft_strlen(line))
	{
		free(line);
		if (sstr)
		{
			free(sstr);
			sstr = NULL;
		}
		return (NULL);
	}
	sstr = ft_new_static_str(sstr);
	return (line);
}

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd;
	int i;

	i = 1;
	fd = open("text.txt", O_RDONLY);
	while(i != 11)
	{
		printf("%d. ", i);
		i++;
		printf("%s", get_next_line(fd));
	}
}