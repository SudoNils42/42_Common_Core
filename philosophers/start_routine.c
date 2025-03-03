/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:08:31 by nbonnet           #+#    #+#             */
/*   Updated: 2025/01/08 15:13:27 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->print_mutex);
	if (check_if_dead(philo) == 1)
		return (1);
	printf("%lld %d has taken a fork\n", get_time_in_ms(), philo->id);
	pthread_mutex_unlock(&philo->print_mutex);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->print_mutex);
	if (check_if_dead(philo) == 1)
		return (1);
	printf("%lld %d has taken a fork\n", get_time_in_ms(), philo->id);
	pthread_mutex_unlock(&philo->print_mutex);
	return (0);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->print_mutex);
	printf("%lld %d is eating\n", get_time_in_ms(), philo->id);
	pthread_mutex_unlock(&philo->print_mutex);
	philo->last_meal = get_time_in_ms();
	usleep(philo->v->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleep_and_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->print_mutex);
	printf("%lld %d is sleeping\n", get_time_in_ms(), philo->id);
	pthread_mutex_unlock(&philo->print_mutex);
	usleep(philo->v->time_to_sleep * 1000);
	pthread_mutex_lock(&philo->print_mutex);
	printf("%lld %d is thinking\n", get_time_in_ms(), philo->id);
	pthread_mutex_unlock(&philo->print_mutex);
}

void	update_meal_count(t_philo *philo)
{
	philo->count_meal++;
	if (philo->v->nbr_time_of_eat != -1
		&& philo->count_meal == philo->v->nbr_time_of_eat
		&& philo->flag_philo_full == 0)
	{
		pthread_mutex_lock(&philo->v->flag_meal_mutex);
		philo->v->flag_meal++;
		philo->flag_philo_full = 1;
		pthread_mutex_unlock(&philo->v->flag_meal_mutex);
	}
}

int	start_routine(t_philo *philo)
{
	while (1)
	{
		if (philo->id % 2 == 0)
			usleep(900);
		if (philo->v->nbr_philo == 1)
		{
			printf("0 1 has taken a fork\n%i 1 died\n", philo->v->time_to_die);
			return (1);
		}
		if (check_if_dead(philo) == 1)
			return (1);
		if (take_forks(philo) == 1)
			return (1);
		if (check_if_dead(philo) == 1)
			return (1);
		eat(philo);
		if (check_if_dead(philo) == 1)
			return (1);
		sleep_and_think(philo);
		if (check_if_dead(philo) == 1)
			return (1);
		update_meal_count(philo);
		if (check_if_dead(philo) == 1)
			return (1);
	}
}
