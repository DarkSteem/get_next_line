/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:23:29 by nberen            #+#    #+#             */
/*   Updated: 2021/12/21 17:31:25 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_read_static_str(int fd, char *str)
{
	char	*buff;
	int		flag;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	flag = -1;
	while (!ft_check_endl(str) && flag)
	{
		flag = read(fd, buff, BUFFER_SIZE);
		if (flag == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[flag] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_static_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	if (!ft_strlen(line))
	{
		free(line);
		if (str)
		{
			free(str);
			str = NULL;
		}
		return (NULL);
	}
	str = ft_new_static_str(str);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	int fd;
// 	int i;

// 	i = 1;
// 	fd = open("text.txt", O_RDONLY);
// 	while(i <= 11)
// 	{
// 		printf("%d. ", i);
// 		i++;
// 		printf("%s", get_next_line(fd));
// 	}
// }