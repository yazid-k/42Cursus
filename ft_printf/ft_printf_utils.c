/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:11:15 by ekadiri           #+#    #+#             */
/*   Updated: 2022/11/20 16:16:56 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_size(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = n * -1;
	}
	while (n != 0)
	{
		n = n / 10;
		++count;
	}
	return (count);
}

int	unsigned_and_hexa_size(unsigned long int n, int base)
{
	int				count;

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

void	ft_putnbr_base_fd(unsigned long int nbr, int fd, char *base)
{
	unsigned long int	size;

	size = ft_strlen(base);
	if (nbr < size)
	{
		ft_putchar_fd(base[nbr], fd);
		return ;
	}
	else
	{
		ft_putnbr_base_fd(nbr / size, fd, base);
		ft_putnbr_base_fd(nbr % size, fd, base);
	}
}

int	ft_xu_printf(unsigned long int nbr, int fd, char *base)
{
	ft_putnbr_base_fd(nbr, fd, base);
	return (unsigned_and_hexa_size(nbr, ft_strlen(base)));
}

int	ft_putstr_printf(char *str, int fd)
{
	if (!str)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}
