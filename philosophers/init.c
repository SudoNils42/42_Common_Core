/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:40:19 by nbonnet           #+#    #+#             */
/*   Updated: 2025/01/08 12:23:09 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_forks(t_v *v)
{
	int	i;

	i = 0;
	while (i < v->nbr_philo)
	{
		pthread_mutex_destroy(&v->forks[i]);
		i++;
	}
	free(v->forks);
	v->forks = NULL;
}

int	init_forks(t_v *v)
{
	int	i;

	v->forks = malloc(sizeof(pthread_mutex_t) * v->nbr_philo);
	if (!v->forks)
		return (1);
	i = 0;
	while (i < v->nbr_philo)
	{
		if (pthread_mutex_init(&v->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

void	init_philo(t_philo *philo, t_v *v)
{
	int	i;

	i = 0;
	while (i < v->nbr_philo)
	{
		memset(&philo[i], 0, sizeof(t_philo));
		philo[i].id = i + 1;
		philo[i].v = v;
		philo[i].left_fork = &v->forks[i];
		if ((i + 1) != v->nbr_philo)
			philo[i].right_fork = &v->forks[i + 1];
		else
			philo[i].right_fork = &v->forks[0];
		philo[i].last_meal = get_time_in_ms();
		i++;
	}
}

int	init_mutex(t_v *v, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < v->nbr_philo)
	{
		if (pthread_mutex_init(&philo[i].print_mutex, NULL) != 0
			|| pthread_mutex_init(&philo[i].death_mutex, NULL) != 0
			|| pthread_mutex_init(&philo[i].meal_mutex, NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&v->flag_meal_mutex, NULL) != 0
		|| pthread_mutex_init(&v->death_flag_mutex, NULL) != 0)
		return (1);
	return (0);
}
