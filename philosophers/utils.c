/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:41:01 by nbonnet           #+#    #+#             */
/*   Updated: 2025/01/08 12:35:30 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(const char *str)
{
	int			i;
	long long	n;
	int			sign;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	return (sign * n);
}

int	is_arg_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			printf("Error\nInput is not only positiv integer\n");
			return (1);
		}
		i++;
	}
	if (ft_atoi(str) > 2147483647)
	{
		printf("Error\nInput higher than int max\n");
		return (1);
	}
	return (0);
}

long long	get_time_in_ms(void)
{
	long long			time_in_ms;
	static long long	start_time = 0;
	struct timeval		tv;

	if (start_time == 0)
	{
		gettimeofday(&tv, NULL);
		start_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	}
	gettimeofday(&tv, NULL);
	time_in_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_in_ms - start_time);
}

void	ft_clean(t_v *v, t_philo *philo, pthread_t **threads)
{
	int	i;

	i = 0;
	while (i < v->nbr_philo)
	{
		pthread_mutex_destroy(&philo[i].print_mutex);
		pthread_mutex_destroy(&philo[i].death_mutex);
		pthread_mutex_destroy(&philo[i].meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&v->flag_meal_mutex);
	pthread_mutex_destroy(&v->death_flag_mutex);
	destroy_forks(v);
	free(philo);
	philo = NULL;
	free(*threads);
	*threads = NULL;
	v->nbr_philo = 0;
	v->time_to_die = 0;
	v->time_to_eat = 0;
	v->time_to_sleep = 0;
	v->nbr_time_of_eat = 0;
	v->flag_meal = 0;
	v->is_dead = 0;
	v->forks = NULL;
}
