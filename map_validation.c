/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:10:14 by aaizza            #+#    #+#             */
/*   Updated: 2022/02/06 01:30:13 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_top_bottom_wall(char **map, int index)
{
	int	i;

	i = 0;
	while (map[index][i])
	{
		if (map[index][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_left_right_wall(char **map, int index)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][index] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_components(char **map)
{
	int	i;
	int	j;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				p++;
			else if (map[i][j] == 'Y')
				g_itachi++;
			else if (map[i][j] == 'C')
				g_total_ramen++;
			else if (map[i][j] == 'E')
				e++;
		}
	}
	return (validate_component(p, e, map));
}

int	check_lines(char **map)
{
	int	i;
	int	len;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	validate_map(char *path, char **map, int count)
{
	int	i;
	int	err;

	i = 0;
	err = 1;
	while (path[i] != '.')
		i++;
	if (ft_strncmp(path + i, ".ber", 4))
		err = 0;
	if (!check_top_bottom_wall(map, 0) \
		|| !check_top_bottom_wall(map, count - 1))
		err = 0;
	if (!check_left_right_wall(map, 0) \
		|| !check_left_right_wall(map, ft_strlen(map[0]) - 1))
		err = 0;
	if (!check_map_components(map) || !check_lines(map))
		err = 0;
	if (!err)
	{
		ft_printf("\n\033[0;31m=> %s\n\n", "INVALID MAP!");
		exit(1);
	}
	return (1);
}
