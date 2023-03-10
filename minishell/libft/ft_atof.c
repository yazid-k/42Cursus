/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:52:41 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/04 19:00:12 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}

static void	clear_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

double	ft_atof(char *str)
{
	float	res;
	char	**tab;
	int		i;

	tab = ft_split(str, '.');
	if (!tab)
		return (0);
	if (!*tab)
		return (free(tab), 0);
	i = 0;
	while (tab[i])
		i++;
	res = ft_atoi(tab[0]);
	if (i > 1)
	{
		if (tab[0][0] == '-')
			res -= (double)ft_atoi(tab[1]) / ft_power(10., ft_strlen(tab[1]));
		else
			res += (double)ft_atoi(tab[1]) / ft_power(10., ft_strlen(tab[1]));
	}
	clear_tab(tab);
	return (res);
}
