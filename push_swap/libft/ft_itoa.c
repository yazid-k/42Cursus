/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:04:26 by ekadiri           #+#    #+#             */
/*   Updated: 2022/11/10 08:37:56 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intsize(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count = 1;
	while (n != 0)
	{
		n = n / 10;
		++count;
	}
	return (count);
}

static int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}

char	*ft_itoa(int n)
{
	int		size;
	char	*res;
	int		i;

	size = intsize(n);
	res = malloc(size + 1);
	i = 0;
	if (n < 0)
	{
		res[i++] = '-';
		if (n == -2147483648)
		{
			res[i++] = '2';
			n = -147483648;
		}
		n *= -1;
	}
	while (i < size)
	{
		res[i] = (n / ft_power(10, size - i - 1)) + 48;
		n -= (n / ft_power(10, size - i - 1)) * ft_power(10, size - i - 1);
		i++;
	}
	res[i] = 0;
	return (res);
}
