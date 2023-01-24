/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:13:06 by ekadiri           #+#    #+#             */
/*   Updated: 2022/11/18 22:04:03 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strchr_gnl(const char *s, int c)
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

static char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	int		size;
	char	*str;

	if (!s1)
		return (ft_strdup(s2));
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, size + 1);
	if (s1)
		free(s1);
	return (str);
}

static char	*str_to_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if (!ft_strchr_gnl(str, '\n'))
		return (str);
	while (str[i] != '\n' && str[i])
		i++;
	line = ft_substr(str, 0, i + 1);
	return (line);
}

static char	*update_str(char *str)
{
	int		i;
	char	*str2;

	if (!str || !ft_strchr_gnl(str, '\n'))
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
	static char	*str[1024];
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	int			bufsize;

	bufsize = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) == -1)
		return (NULL);
	while (bufsize > 0 && !ft_strchr_gnl(str[fd], '\n'))
	{
		bufsize = read(fd, buf, BUFFER_SIZE);
		buf[bufsize] = 0;
		if (bufsize == 0)
			break ;
		str[fd] = ft_strjoin_gnl(str[fd], buf);
	}
	line = str_to_line(str[fd]);
	str[fd] = update_str(str[fd]);
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
