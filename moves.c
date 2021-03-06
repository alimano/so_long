/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:10:19 by aaizza            #+#    #+#             */
/*   Updated: 2022/02/06 01:30:02 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(char **map, t_Player *p)
{
	if (map[p->y + 1][p->x] != '1' && map[p->y + 1][p->x] != 'E')
		p->y = p->y + 1;
	else if (map[p->y + 1][p->x] == 'E' && g_ramen == g_total_ramen)
		p->y = p->y + 1;
}

void	move_up(char **map, t_Player *p)
{
	if (map[p->y - 1][p->x] != '1' && map[p->y - 1][p->x] != 'E')
		p->y = p->y - 1;
	else if (map[p->y - 1][p->x] == 'E' && g_ramen == g_total_ramen)
		p->y = p->y - 1;
}

void	move_left(char **map, t_Player *p)
{
	if (map[p->y][p->x + 1] != '1' && map[p->y][p->x + 1] != 'E')
		p->x = p->x + 1;
	else if (map[p->y][p->x + 1] == 'E' && g_ramen == g_total_ramen)
		p->x = p->x + 1;
	g_naruto = "./images/narutoright.xpm";
}

void	move_right(char **map, t_Player *p)
{
	if (map[p->y][p->x - 1] != '1' && map[p->y][p->x - 1] != 'E')
		p->x = p->x - 1;
	else if (map[p->y][p->x - 1] == 'E' && g_ramen == g_total_ramen)
		p->x = p->x - 1;
	g_naruto = "./images/narutoleft.xpm";
}

int	validate_component(int p, int e, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
				&& map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'Y')
			{
				ft_printf("\n\033[0;31m=> %s\n\n", "WRONG VARIABLE!");
				exit(1);
			}
			j++;
		}
		i++;
	}
	if (e < 1 || g_total_ramen < 1 || p != 1)
		return (0);
	return (1);
}
