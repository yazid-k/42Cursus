/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:05:55 by ekadiri           #+#    #+#             */
/*   Updated: 2022/11/07 14:36:37 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
		return (i);
	}
	return (count);
}

static int	word_size(char *str, char c, int index)
{

}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = malloc(sizeof(char *) * word_count(s, c) + 1);
	if (!array)
		return (NULL);
	array[word_count(s, c)] = 0;
	return (array);
}
