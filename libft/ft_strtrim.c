/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:06:03 by ekadiri           #+#    #+#             */
/*   Updated: 2022/11/13 20:06:17 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	get_start_index(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && char_in_set(s1[i], set))
		i++;
	return (i);
}

static int	get_last_index(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i > 0 && char_in_set(s1[i], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = get_start_index(s1, set);
	end = get_last_index(s1, set);
	res = ft_substr(s1, start, end - start + 1);
	return (res);
}
