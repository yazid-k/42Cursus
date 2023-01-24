/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:24:25 by ekadiri           #+#    #+#             */
/*   Updated: 2022/11/19 22:36:11 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd_printf(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	ft_putnbr_printf(int nbr, int fd)
{
	ft_putnbr_fd(nbr, fd);
	return (int_size(nbr));
}

int	print_address(unsigned long int addr)
{
	if (!addr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd(addr, 1, "0123456789abcdef");
	return (unsigned_and_hexa_size(addr, 16) + 2);
}

int	print_arg(va_list arg, char c)
{
	if (c == 'c')
		return (ft_putchar_fd_printf((char)va_arg(arg, int), 1));
	if (c == 's')
		return (ft_putstr_printf(va_arg(arg, char *), 1));
	if (c == '%')
		return (ft_putchar_fd_printf('%', 1));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_printf(va_arg(arg, int), 1));
	if (c == 'u')
		return (ft_xu_printf(va_arg(arg, unsigned int), 1, "0123456789"));
	if (c == 'x')
		return (ft_xu_printf(va_arg(arg, unsigned int), 1, "0123456789abcdef"));
	if (c == 'X')
		return (ft_xu_printf(va_arg(arg, unsigned int), 1, "0123456789ABCDEF"));
	if (c == 'p')
		return (print_address(va_arg(arg, unsigned long int)));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	int		i;
	va_list	args;

	va_start(args, s);
	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			len += print_arg(args, s[i++]);
		}
		else
		{
			ft_putchar_fd(s[i++], 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}
