/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_com_swap_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:28:13 by nbonnet           #+#    #+#             */
/*   Updated: 2024/12/04 16:32:09 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_var *var)
{
	int	temp;

	if (var->size_a < 2)
		return ;
	temp = var->a[0];
	var->a[0] = var->a[1];
	var->a[1] = temp;
	ft_printf("sa\n");
}

void	swap_b(t_var *var)
{
	int	temp;

	if (var->size_b < 2)
		return ;
	temp = var->b[0];
	var->b[0] = var->b[1];
	var->b[1] = temp;
	ft_printf("sb\n");
}

void	swap_ss(t_var *var)
{
	if (var->size_a < 2 && var->size_a < 2)
		return ;
	if (var->size_a < 2)
		swap_a(var);
	if (var->size_b < 2)
		swap_b(var);
	ft_printf("ss\n");
}

void	push_a(t_var *var)
{
	int	i;

	if (var->size_b == 0)
		return ;
	i = var->size_a;
	while (i > 0)
	{
		var->a[i] = var->a[i - 1];
		i--;
	}
	var->a[0] = var->b[0];
	var->size_a++;
	i = 0;
	while (i < var->size_b - 1)
	{
		var->b[i] = var->b[i + 1];
		i++;
	}
	var->size_b--;
	ft_printf("pa\n");
}

void	push_b(t_var *var)
{
	int	i;

	if (var->size_a == 0)
		return ;
	i = var->size_b;
	while (i > 0)
	{
		var->b[i] = var->b[i - 1];
		i--;
	}
	var->b[0] = var->a[0];
	var->size_b++;
	i = 0;
	while (i < var->size_a - 1)
	{
		var->a[i] = var->a[i + 1];
		i++;
	}
	var->size_a--;
	ft_printf("pb\n");
}
