/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:05:25 by ekadiri           #+#    #+#             */
/*   Updated: 2022/11/07 13:54:45 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*c;

	c = malloc(ft_strlen(s1) + 1);
	if (c == NULL)
		return (NULL);
	ft_strlcpy(c, s1, ft_strlen(s1));
	return (c);
}
