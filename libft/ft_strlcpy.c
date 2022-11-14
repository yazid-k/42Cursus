/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:47:48 by ekadiri           #+#    #+#             */
/*   Updated: 2022/11/10 08:38:48 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}
/*
#include <bsd/string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	char	*src1;
	char	*src2;
	char	*dst1;
	char	*dst2;
	dst1 = argv[1];
	dst2 = dst1;
	src1 = argv[2];
	src2 = src1;
	printf("%ld, %s\n%ld, %s", ft_strlcpy(dst1, src1, ft_atoi(argv[3])),
	dst1, strlcpy(dst2, src2, ft_atoi(argv[3])), dst2);
	return 0;
}
*/
