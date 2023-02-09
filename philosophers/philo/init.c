/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:29:26 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/08 13:31:57 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**init_philosophers(char **av)
{
	t_philo	**philo;

	philo = malloc(ft_atoi(av[1]) * sizof(s_philo));
	if (!philo)
		return(NULL);
}
