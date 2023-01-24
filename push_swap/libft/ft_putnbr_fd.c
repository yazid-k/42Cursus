/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:05:05 by ekadiri           #+#    #+#             */
/*   Updated: 2022/11/23 15:00:37 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_size(int n)
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

int	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-", 1);
		ft_putchar_fd(2 + 48, fd);
		n = 147483648;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + 48, fd);
		return (int_size(n));
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putnbr_fd(n % 10, fd);
	return (int_size(n));
}
