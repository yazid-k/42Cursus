/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:24:22 by ekadiri           #+#    #+#             */
/*   Updated: 2022/11/19 22:36:09 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
size_t	ft_strlen(char *str);
int		ft_putnbr_base_printf(unsigned long int nbr, int fd, char *base);
int		ft_putstr_printf(char *str, int fd);
int		unsigned_and_hexa_size(unsigned long int n, int base);
int		int_size(int n);
void	ft_putnbr_base_fd(unsigned long int nbr, int fd, char *base);
int		ft_xu_printf(unsigned long int nbr, int fd, char *base);
int		ft_putstr_printf(char *str, int fd);
int		ft_putchar_fd_printf(char c, int fd);
int		ft_putnbr_printf(int nbr, int fd);
int		print_arg(va_list arg, char c);

#endif
