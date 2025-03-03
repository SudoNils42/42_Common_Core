/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:34:33 by nbonnet           #+#    #+#             */
/*   Updated: 2025/01/08 15:13:22 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_end(t_v *v, t_philo *philo)
{
	pthread_mutex_lock(&philo->death_mutex);
	if (get_time_in_ms() - philo->last_meal >= philo->v->time_to_die)
	{
		pthread_mutex_lock(&v->death_flag_mutex);
		v->is_dead = 1;
		pthread_mutex_unlock(&v->death_flag_mutex);
		pthread_mutex_lock(&philo->print_mutex);
		printf("%lld %d died\n", get_time_in_ms(), philo->id);
		pthread_mutex_unlock(&philo->print_mutex);
		pthread_mutex_unlock(&philo->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->death_mutex);
	return (0);
}

void	*ft_end_checker(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < philo->v->nbr_philo)
		{
			if ((philo->v->flag_meal == philo->v->nbr_philo)
				|| check_end(philo->v, &philo[i]) == 1)
			{
				pthread_mutex_lock(&philo->v->death_flag_mutex);
				philo->v->is_dead = 1;
				pthread_mutex_unlock(&philo->v->death_flag_mutex);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

int	check_if_dead(t_philo *philo)
{
	if (philo->v->is_dead)
	{
		pthread_mutex_unlock(&philo->v->death_flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->v->death_flag_mutex);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->v->nbr_time_of_eat == 0)
		return (NULL);
	philo->v->flag_meal = 1;
	philo->last_meal = 0;
	philo->flag_philo_full = 0;
	philo->count_meal = 0;
	if (start_routine(philo) == 1)
		return (NULL);
	return (NULL);
}
