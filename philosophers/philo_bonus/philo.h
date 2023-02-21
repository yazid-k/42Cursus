/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:17:03 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/13 18:55:17 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef struct s_philo
{
	int			id;
	int			left_pid;
	int			right_pid;
	int			left_fid;
	int			right_fid;
	int			t_eat;
	pthread_t	thread;
}	t_philo;

typedef struct s_rules
{
	int		death;
	int		eat;
	int		sleep;
	int		n_eat;
	t_philo	philo[1024];
}	t_rules;

int		parse(int ac, char **av);
int		is_number(char *str);

//Utils
int		ft_atoi(const char *str);
t_rules	*init_all(int ac, char **av);
void	free_tab(t_philo **tab);

#endif
