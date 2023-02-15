/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:52:54 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/05 13:01:22 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	str_isnumber(char *str)
{
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	if (!ft_strncmp(str, "-0", 2))
		return (1);
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

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	str_isfloat(char *str)
{
	char	**tab;
	int		i;
	int		j;

	tab = ft_split(str, '.');
	if (!tab)
		return (0);
	if (!*tab)
		return (free(tab), 0);
	i = 0;
	while (tab[i])
		i++;
	if ((i != 2 && i != 1) || !str_isnumber(tab[0]))
		return (free_tab(tab), 0);
	if (i == 2)
	{
		j = -1;
		while (tab[1][++j])
		{
			if (!ft_isdigit(tab[1][j]))
				return (free_tab(tab), 0);
		}
	}
	return (free_tab(tab), 1);
}

int	parse(int ac, char **av)
{
	if (ac < 2)
		return (ft_printf("Not enough arguments\n"), 0);
	if (ft_strncmp(av[1], "Mandelbrot", max(10, ft_strlen(av[1])))
		&& ft_strncmp(av[1], "Julia", max(6, ft_strlen(av[1])))
		&& ft_strncmp(av[1], "BurningShip", max(11, ft_strlen(av[1]))))
		return (ft_printf("Sets :\n- Julia\n- Mandelbrot\n- BurningShip\n"), 0);
	if (!ft_strncmp(av[1], "Julia", max(6, ft_strlen(av[1]))))
	{
		if (ac != 4)
			return (ft_printf("2 arguments needed for Julia set\n"), 0);
		if (!str_isfloat(av[2]) || !str_isfloat(av[3]))
			return (ft_printf("Numeric arguments needed\n"), 0);
	}
	return (1);
}
