/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:35:01 by nbonnet           #+#    #+#             */
/*   Updated: 2024/12/04 22:22:57 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoll(t_var *var, char *str)
{
	int	i;

	i = 0;
	var->sign = 1;
	var->n = 0;
	while (str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		var->sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		var->n = (var->n * 10) + (str[i] - 48);
		i++;
	}
	if ((var->n > 2147483647 || var->n < -2147483648) || (str[i] != '\0'))
	{
		var->flag2 = 1;
		return (0);
	}
	return (var->sign * var->n);
}

int	is_sorted(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->size_a - 1)
	{
		if (var->a[i] > var->a[i + 1])
			return (0);
		i++;
	}
	ft_free(var);
	return (1);
}

int	check_double(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->tot_nbr)
	{
		j = i + 1;
		while (j < var->tot_nbr)
		{
			if (var->a[i] == var->a[j])
			{
				ft_free(var);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_error(t_var *var)
{
	var->flag2 = 0;
	while (var->i < var->tot_nbr)
	{
		var->a[var->i] = ft_atoll(var, var->tab[var->i]);
		if (var->flag2 == 1)
		{
			write(2, "Error\n", 7);
			ft_free(var);
			return (0);
		}
		var->i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_var	var;

	if (ac == 2)
	{
		if (ft_error(av[1]) == 0)
			return (0);
	}
	if (arg_to_tab(&var, ac, av) == 0)
		return (0);
	if (ft_alloc(&var) == 0)
		return (0);
	make_index(&var);
	if (check_double(&var) == 1)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	if (is_sorted(&var) == 1)
		return (0);
	ft_sort(&var);
	ft_free(&var);
	return (0);
}
