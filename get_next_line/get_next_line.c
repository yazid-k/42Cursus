/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:13:06 by ekadiri           #+#    #+#             */
/*   Updated: 2022/11/18 17:54:21 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c && s[i] == '\0')
		return ((char *)s + ft_strlen(s));
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	size;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	size = len;
	if (len > ft_strlen(s) - start)
		size = ft_strlen(s) - start;
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*str_to_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if (!ft_strchr(str, '\n'))
		return (str);
	while (str[i] != '\n' && str[i])
		i++;
	line = ft_substr(str, 0, i + 1);
	return (line);
}

char	*update_str(char *str)
{
	int		i;
	char	*str2;

	if (!str || !ft_strchr(str, '\n'))
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	str2 = ft_substr(str, i + 1, ft_strlen(str) - i - 1);
	free(str);
	if (ft_strlen(str2) == 0)
	{
		free(str2);
		return (NULL);
	}
	return (str2);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	int			bufsize;

	bufsize = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) == -1)
		return (NULL);
	while (bufsize > 0 && !ft_strchr(str, '\n'))
	{
		bufsize = read(fd, buf, BUFFER_SIZE);
		buf[bufsize] = 0;
		if (bufsize == 0)
			break ;
		str = ft_strjoin_gnl(str, buf);
	}
	line = str_to_line(str);
	str = update_str(str);
	return (line);
}

/* #include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	i;

	i = 1;
	int fd = open("test", O_RDONLY);
	char	*line = get_next_line(fd);
	while (line)
	{
		printf("%d : %s", i++, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}
 */
