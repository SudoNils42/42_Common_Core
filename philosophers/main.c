/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:36:20 by nbonnet           #+#    #+#             */
/*   Updated: 2025/01/08 16:09:35 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	manage_args(int ac, char **av, t_v *v)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error\n4 or 5 arguments needed\n");
		return (1);
	}
	if (is_arg_valid(av[1]) || is_arg_valid(av[2]) || is_arg_valid(av[3])
		|| is_arg_valid(av[4]) == 1)
		return (1);
	v->nbr_philo = ft_atoi(av[1]);
	v->time_to_die = ft_atoi(av[2]);
	v->time_to_eat = ft_atoi(av[3]);
	v->time_to_sleep = ft_atoi(av[4]);
	v->nbr_time_of_eat = -1;
	v->is_dead = 0;
	if (ac == 6)
	{
		if (is_arg_valid(av[5]) == 1)
			return (1);
		v->nbr_time_of_eat = ft_atoi(av[5]);
		if (v->nbr_time_of_eat <= 0)
			return (1);
	}
	return (0);
}

int	manage_threads(t_v *v, t_philo *philo, pthread_t **threads)
{
	int			i;
	pthread_t	death_checker;

	i = 0;
	*threads = malloc(sizeof(pthread_t) * v->nbr_philo);
	if (!(*threads))
	{
		printf("Error\nmalloc threads\n");
		return (1);
	}
	while (i < v->nbr_philo)
	{
		pthread_create(&(*threads)[i], NULL, &routine, &philo[i]);
		i++;
	}
	i = 0;
	pthread_create(&death_checker, NULL, ft_end_checker, philo);
	pthread_join(death_checker, NULL);
	while (i < v->nbr_philo)
	{
		pthread_join((*threads)[i], NULL);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_v			v;
	t_philo		*philo;
	pthread_t	*threads;

	if (manage_args(ac, av, &v) == 1)
		return (1);
	if (v.nbr_philo == 0 || v.time_to_die == 0 || v.time_to_eat == 0
		|| v.time_to_sleep == 0)
	{
		printf("Error\nArguments has to be greater than 0\n");
		return (1);
	}
	philo = malloc(sizeof(t_philo) * v.nbr_philo);
	if (!philo)
		return (1);
	if (init_mutex(&v, philo) != 0)
		return (1);
	if (init_forks(&v) == 1)
		return (1);
	init_philo(philo, &v);
	if (manage_threads(&v, philo, &threads) == 1)
		return (1);
	ft_clean(&v, philo, &threads);
	return (0);
}
