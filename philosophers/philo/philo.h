/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:17:03 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/12 20:02:20 by ekadiri          ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	int				t_eat;
	pthread_t		thread;
	long int		last_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	eat;
	struct s_rules	*rules;
}	t_philo;

typedef struct s_rules
{
	int				n;
	int				death;
	int				eat;
	int				sleep;
	int				n_eat;
	int				end;
	pthread_mutex_t	print;
	pthread_mutex_t	monitor;
	t_philo			philo[200];
	pthread_mutex_t	fork[200];
}	t_rules;

int		parse(int ac, char **av);
int		is_number(char *str);

//Utils
int		ft_atoi(const char *str);
t_philo	init_philo(int id, t_rules *rules);
t_rules	*init_all(int ac, char **av);
long	get_timestamp(void);
void	print_action(t_philo philo, int action);
void	free_all(t_rules *rules);
int		min(int a, int b);
int		max(int a, int b);
int		check_death(t_philo *philo);

//Actions
void	start(t_rules *rules);

#endif
