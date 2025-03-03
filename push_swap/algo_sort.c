/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:03:50 by nbonnet           #+#    #+#             */
/*   Updated: 2024/12/04 22:40:45 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_to_tab(t_var *var, int ac, char **av)
{
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		var->tab = ft_split(av[1], ' ');
		if (!var->tab)
			return (0);
		var->flag = 1;
		var->tot_nbr = 0;
		while (var->tab[var->tot_nbr] != NULL)
			var->tot_nbr++;
	}
	else
	{
		var->tot_nbr = ac - 1;
		var->tab = av + 1;
	}
	if (var->tot_nbr == 1)
	{
		var->a = NULL;
		var->b = NULL;
		ft_free(var);
		return (0);
	}
	return (1);
}

void	ft_sort(t_var *var)
{
	if (var->tot_nbr < 2)
		return ;
	else if (var->tot_nbr == 2)
		sort_two(var);
	else if (var->tot_nbr == 3)
		sort_three(var);
	else if (var->tot_nbr == 4)
		sort_four(var);
	else if (var->tot_nbr == 5)
		sort_five(var);
	else
	{
		var->max_num = var->a[0];
		var->i = 0;
		while (++var->i < var->size_a)
		{
			if (var->a[var->i] > var->max_num)
				var->max_num = var->a[var->i];
		}
		var->max_bits = 0;
		algo_sort(var);
	}
}

void	make_index(t_var *var)
{
	int	i;
	int	j;
	int	index;
	int	*temp_a;

	temp_a = malloc(sizeof(int) * var->tot_nbr);
	if (!temp_a)
		return ;
	i = -1;
	while (++i < var->tot_nbr)
	{
		index = 0;
		j = 0;
		while (j < var->tot_nbr)
		{
			if (var->a[i] > var->a[j])
				index++;
			j++;
		}
		temp_a[i] = index;
	}
	i = -1;
	while (++i < var->tot_nbr)
		var->a[i] = temp_a[i];
	free(temp_a);
}

void	algo_sort(t_var *var)
{
	int	i;

	while ((var->max_num >> var->max_bits) != 0)
		var->max_bits++;
	var->bit = 0;
	while (var->bit < var->max_bits)
	{
		var->initial_size = var->size_a;
		i = 0;
		while (i < var->initial_size)
		{
			if (((var->a[0] >> var->bit) & 1) == 0)
				push_b(var);
			else
				rotate_a(var);
			i++;
		}
		while (var->size_b > 0)
			push_a(var);
		var->bit++;
	}
}
