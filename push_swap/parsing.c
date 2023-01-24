/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:36:11 by ekadiri           #+#    #+#             */
/*   Updated: 2023/01/24 20:08:30 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_isnumber(char *str)
{
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	j = ft_atoi(str);
	tmp = ft_itoa(j);
	if (ft_strncmp(tmp, str, ft_strlen(tmp)))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	if ((size_t)i == ft_strlen(str))
		return (1);
	return (0);
}

int	check_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!str_isnumber(av[i]))
			return (0);
		i++;
	}
	if (!check_duplicates(av))
		return (0);
	return (1);
}
