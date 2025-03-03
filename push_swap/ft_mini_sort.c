/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:19:08 by nbonnet           #+#    #+#             */
/*   Updated: 2024/12/04 16:32:11 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_first_second(t_var *var)
{
	int	i;

	i = 0;
	var->first = var->a[0];
	var->second = var->a[1];
	while (i < var->size_a)
	{
		if (var->a[i] < var->first)
		{
			var->second = var->first;
			var->first = var->a[i];
		}
		else if (var->a[i] < var->second && var->a[i] > var->first)
			var->second = var->a[i];
		i++;
	}
}

void	sort_two(t_var *var)
{
	if (var->a[0] > var->a[1])
		swap_a(var);
}

void	sort_three(t_var *var)
{
	if (var->a[0] > var->a[1])
		swap_a(var);
	if (var->a[1] > var->a[2])
		reverse_rotate_a(var);
	if (var->a[0] > var->a[1])
		swap_a(var);
}

void	sort_four(t_var *var)
{
	int	i;

	i = 0;
	find_first_second(var);
	while (var->a[i] != var->first)
		i++;
	if (i == 1)
		swap_a(var);
	if (i == 2)
	{
		rotate_a(var);
		rotate_a(var);
	}
	else if (i == 3)
		reverse_rotate_a(var);
	push_b(var);
	sort_three(var);
	push_a(var);
}

void	sort_five(t_var *var)
{
	int	i;

	i = 0;
	find_first_second(var);
	while (var->a[i] != var->first)
		i++;
	if (i == 1)
		swap_a(var);
	if (i == 2)
	{
		rotate_a(var);
		rotate_a(var);
	}
	else if (i == 3)
	{
		reverse_rotate_a(var);
		reverse_rotate_a(var);
	}
	else if (i == 4)
		reverse_rotate_a(var);
	push_b(var);
	sort_four(var);
	push_a(var);
}
