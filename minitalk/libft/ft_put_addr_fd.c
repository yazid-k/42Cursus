/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_addr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:53:04 by ekadiri           #+#    #+#             */
/*   Updated: 2022/11/23 15:01:44 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	addr_size(unsigned long int n, int base)
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

int	ft_put_addr_fd(unsigned long int addr, int fd)
{
	if (!addr)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	ft_putstr_fd("0x", fd);
	ft_put_base_fd(addr, fd, "0123456789abcdef");
	return (addr_size(addr, 16) + 2);
}
