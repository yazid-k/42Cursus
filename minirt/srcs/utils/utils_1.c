/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:11:33 by ekadiri           #+#    #+#             */
/*   Updated: 2023/05/25 17:18:02 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	free_arr(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	print_arr(char **arr)
{
	while (*arr)
	{
		printf("%s\n", *arr);
		arr++;
	}
}

int	str_is_float(char *str)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = -1;
	count = 0;
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (str[i] == '.')
				count++;
		if (count >= 2 || (!ft_isdigit(str[i]) && str[i] != '.'))
			return (0);
	}
	return (1);
}

int	str_is_int(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}
