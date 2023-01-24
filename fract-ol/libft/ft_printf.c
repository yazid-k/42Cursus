/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:24:25 by ekadiri           #+#    #+#             */
/*   Updated: 2022/12/03 12:23:01 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_arg(va_list arg, char c)
{
	char	*x;
	char	*x_maj;

	x = "0123456789abcdef";
	x_maj = "0123456798ABCDEF";
	if (c == 'c')
		return (ft_putchar_fd((char)va_arg(arg, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(arg, char *), 1));
	if (c == '%')
		return (ft_putchar_fd('%', 1));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(arg, int), 1));
	if (c == 'u')
		return (ft_put_base_fd(va_arg(arg, unsigned int), 1, "0123456789"));
	if (c == 'x')
		return (ft_put_base_fd(va_arg(arg, unsigned int), 1, x));
	if (c == 'X')
		return (ft_put_base_fd(va_arg(arg, unsigned int), 1, x_maj));
	if (c == 'p')
		return (ft_put_addr_fd(va_arg(arg, unsigned long int), 1));
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
