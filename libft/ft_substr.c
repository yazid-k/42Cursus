/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:49:37 by ekadiri           #+#    #+#             */
/*   Updated: 2022/11/08 18:56:42 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
