/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:54:17 by nbonnet           #+#    #+#             */
/*   Updated: 2024/12/04 22:03:12 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_alloc(t_var *var)
{
	var->i = 0;
	var->a = malloc(sizeof(int) * var->tot_nbr);
	if (!var->a)
		return (0);
	var->b = malloc(sizeof(int) * var->tot_nbr);
	if (!var->b)
		return (0);
	if (check_error(var) == 0)
		return (0);
	var->size_a = var->tot_nbr;
	var->size_b = 0;
	return (1);
}

void	ft_free(t_var *var)
{
	int	i;

	i = 0;
	if (var->a != NULL)
	{
		free(var->a);
		var->a = NULL;
	}
	if (var->b != NULL)
	{
		free(var->b);
		var->b = NULL;
	}
	if (var->flag == 1)
	{
		while (var->tab[i])
		{
			free(var->tab[i]);
			var->tab[i] = NULL;
			i++;
		}
		free(var->tab);
		var->tab = NULL;
	}
}
