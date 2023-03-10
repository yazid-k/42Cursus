/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:05:55 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/04 17:56:42 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	word_size(char const *s, char c, int index)
{
	int	size;
	int	i;

	i = index;
	size = 0;
	while (s[i] != c && s[i])
	{
		i++;
		size++;
	}
	return (size);
}

static void	clear_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

static int	get_word(char const *s, char c, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (j < word_count(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		tab[j] = malloc(word_size(s, c, i) + 1);
		if (!tab[j])
		{
			clear_tab(tab);
			return (0);
		}
		k = 0;
		while (s[i] != c && s[i])
			tab[j][k++] = s[i++];
		tab[j++][k] = 0;
		while (s[i] != c && s[i])
			i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!array)
		return (NULL);
	if (!get_word(s, c, array))
		return (NULL);
	array[word_count(s, c)] = 0;
	return (array);
}
