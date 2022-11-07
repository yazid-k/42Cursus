/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:06:03 by ekadiri           #+#    #+#             */
/*   Updated: 2022/11/07 13:33:45 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		i;
	int		j;
	int		size;

	i = -1;
	size = 0;
	while (s[++i])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			size++;
	}
	res = malloc(size);
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			res[j++] = s[i];
	}
	res[j] = '\0';
	return (res);
}
