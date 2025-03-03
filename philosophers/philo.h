/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:28:19 by nbonnet           #+#    #+#             */
/*   Updated: 2025/01/08 15:11:52 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_v
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_time_of_eat;
	int				flag_meal;
	int				is_dead;

	pthread_mutex_t	death_flag_mutex;
	pthread_mutex_t	flag_meal_mutex;
	pthread_mutex_t	*forks;
}					t_v;

typedef struct s_philo
{
	int				id;
	int				count_meal;
	int				flag_philo_full;
	pthread_t		*threads;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	meal_mutex;
	long long		last_meal;
	struct s_v		*v;

}					t_philo;

long long			ft_atoi(const char *str);
int					is_arg_valid(char *str);
void				init_philo(t_philo *philo, t_v *v);
void				*routine(void *arg);
int					init_forks(t_v *v);
void				destroy_forks(t_v *v);
long long			get_time_in_ms(void);
void				*ft_end_checker(void *arg);
void				ft_clean(t_v *v, t_philo *philo, pthread_t **threads);
int					init_mutex(t_v *v, t_philo *philo);
int					take_forks(t_philo *philo);
void				eat(t_philo *philo);
void				sleep_and_think(t_philo *philo);
void				update_meal_count(t_philo *philo);
int					start_routine(t_philo *philo);
int					check_if_dead(t_philo *philo);
int					check_end(t_v *v, t_philo *philo);

#endif
