/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:17:03 by ekadiri           #+#    #+#             */
/*   Updated: 2023/03/09 01:20:39 by ekadiri          ###   ########.fr       */
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

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

typedef struct s_fork
{
	int				id;
	int				available;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				left_pid;
	int				right_pid;
	int				l_fork;
	int				r_fork;
	int				forks;
	int				t_eat;
	pthread_t		thread;
	long int		last_meal;
	struct s_rules	*rules;
}	t_philo;

typedef struct s_rules
{
	int				n;
	int				death;
	int				eat;
	int				sleep;
	int				n_eat;
	pthread_mutex_t	print;
	t_philo			philo[200];
	t_fork			fork[200];
}	t_rules;

int		parse(int ac, char **av);
int		is_number(char *str);

//Utils
int		ft_atoi(const char *str);
t_fork	init_fork(int id);
t_philo	init_philo(int id, char **av);
t_rules	*init_all(int ac, char **av);
long	get_timestamp(void);
void	print_action(t_philo philo, int action);
void	free_all(t_rules *rules);
void	update_fork(t_fork *fork, t_philo *philo);

//Actions
void	start(t_rules *rules);

#endif
