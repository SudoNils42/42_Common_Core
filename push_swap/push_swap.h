/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:38:57 by nbonnet           #+#    #+#             */
/*   Updated: 2024/12/04 22:05:40 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_var
{
	int			i;
	int			tot_nbr;
	int			*a;
	int			*b;
	char		**tab;
	int			size_a;
	int			size_b;
	int			sign;
	long long	n;
	int			first;
	int			second;
	int			max_num;
	int			max_bits;
	int			initial_size;
	int			bit;
	int			temp;
	int			j;
	int			flag;
	int			flag2;

}				t_var;

void			swap_a(t_var *var);
void			swap_b(t_var *var);
void			swap_ss(t_var *var);
void			push_a(t_var *var);
void			push_b(t_var *var);
void			rotate_a(t_var *var);
void			rotate_b(t_var *var);
void			rotate_ab(t_var *var);
void			reverse_rotate_a(t_var *var);
void			reverse_rotate_b(t_var *var);
void			reverse_rotate_ab(t_var *var);
void			find_first_second(t_var *var);
void			sort_two(t_var *var);
void			sort_three(t_var *var);
void			sort_four(t_var *var);
void			sort_five(t_var *var);
void			algo_sort(t_var *var);
int				is_sorted(t_var *var);
void			find_first_secondb(t_var *var);
void			sort_twob(t_var *var);
void			sort_threeb(t_var *var);
void			sort_fourb(t_var *var);
void			sort_fiveb(t_var *var);
void			ft_sort(t_var *var);
int				arg_to_tab(t_var *var, int ac, char **av);
void			ft_free(t_var *var);
void			make_index(t_var *var);
int				ft_error(char *str);
int				ft_alloc(t_var *var);
int				check_error(t_var *var);

#endif
