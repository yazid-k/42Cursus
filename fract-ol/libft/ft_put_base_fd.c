/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:49:40 by ekadiri           #+#    #+#             */
/*   Updated: 2022/11/23 15:02:09 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	unsigned_and_hexa_size(unsigned long int n, int base)
{
	int		count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		++count;
	}
	return (count);
}

int	ft_put_base_fd(unsigned long int nbr, int fd, char *base)
{
	if (nbr < ft_strlen(base))
	{
		ft_putchar_fd(base[nbr], fd);
		return (unsigned_and_hexa_size(nbr, ft_strlen(base)));
	}
	else
	{
		ft_put_base_fd(nbr / ft_strlen(base), fd, base);
		ft_put_base_fd(nbr % ft_strlen(base), fd, base);
	}
	return (unsigned_and_hexa_size(nbr, ft_strlen(base)));
}
