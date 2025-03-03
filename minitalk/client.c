/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:33:17 by nbonnet           #+#    #+#             */
/*   Updated: 2024/12/12 14:53:29 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else if (bit == 1)
		kill(pid, SIGUSR2);
	usleep(100);
}

void	send_str(pid_t pid, char *str)
{
	int		i;
	char	c;
	int		j;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		j = 7;
		while (j >= 0)
		{
			send_bit(pid, (c >> j) & 1);
			j--;
		}
		i++;
	}
	j = 7;
	while (j >= 0)
	{
		send_bit(pid, (0 >> j) & 1);
		j--;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_printf("Use this form: PID \"message\"\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	send_str(pid, av[2]);
	return (0);
}
