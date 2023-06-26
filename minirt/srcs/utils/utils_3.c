/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:00:17 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/26 16:02:36 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_elem	*get_elem_by_type(t_data *data, t_type type)
{
	static t_elem	*tmp;

	if (!tmp)
		tmp = data->elem;
	while (tmp)
	{
		if (tmp->type == type)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = NULL;
	return (NULL);
}
