/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:39:43 by lfaria-m          #+#    #+#             */
/*   Updated: 2025/04/22 13:26:04 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	strip_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_allowed_char(line[i]) && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strdup_trimmed(char *str)
{
	int		i;
	int		len;
	char	*res;
	int		j;

	i = 0;
	len = ft_strlen(str);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (len > i && (str[len - 1] == ' ' || str[len - 1] == '\t' || str[len
				- 1] == '\n'))
		len--;
	res = malloc(len - i + 1);
	if (!res)
		return (NULL);
	j = 0;
	while (i < len)
		res[j++] = str[i++];
	res[j] = '\0';
	return (res);
}

int	is_walled_in(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->len_y)
	{
		if ((map->map_2d[i][0] != '1' && map->map_2d[i][0] != ' ')
			|| (map->map_2d[i][map->len_x - 1] != '1'
				&& map->map_2d[i][map->len_x - 1] != ' '))
			return (0);
		i++;
	}
	i = 0;
	while (i < map->len_x)
	{
		if ((map->map_2d[0][i] != '1' && map->map_2d[0][i] != ' ')
			|| (map->map_2d[map->len_y - 1][i] != '1' && map->map_2d[map->len_y
				- 1][i] != ' '))
			return (0);
		i++;
	}
	return (1);
}
