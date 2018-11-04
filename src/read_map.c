/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:10:58 by vmartynu          #+#    #+#             */
/*   Updated: 2018/09/11 10:13:17 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		init_border_map(t_sdl *sd, int z, int i, char **map)
{
	int			j;

	if (i == 0 || i == sd->map_h[z] - 1)
	{
		j = 0;
		while (j < sd->map_w[z])
		{
			if (map[i][j] == '\0')
				break ;
			if (ft_chartoi(map[i][j]) <= 0)
				sd->map[z][i][j] = 1;
			else
				sd->map[z][i][j] = ft_chartoi(map[i][j]);
			j++;
		}
	}
	else
	{
		j = 0;
		while (j < sd->map_w[z] && j < (int)ft_strlen(map[i]) - 1)
		{
			sd->map[z][i][j] = ft_chartoi(map[i][j]);
			j++;
		}
	}
}

static void		init_int_map(t_sdl *sd, int z, int i, char **map)
{
	if (ft_chartoi(map[i][0]) <= 0)
		sd->map[z][i][0] = 1;
	else
		sd->map[z][i][0] = ft_chartoi(map[i][0]);
	if (ft_chartoi(map[i][(int)ft_strlen(map[i]) - 1]) <= 0)
		sd->map[z][i][(int)ft_strlen(map[i]) - 1] = 1;
	else
		sd->map[z][i][(int)ft_strlen(map[i]) - 1] =
		ft_chartoi(map[i][(int)ft_strlen(map[i]) - 1]);
}

int				read_map(t_sdl *sd, int *fd)
{
	int			i;
	int			z;
	char		**map;

	i = 0;
	z = 0;
	while (z < LEVELS)
	{
		sd->map_h[z] = 0;
		sd->map_w[z] = 1;
		if (!(map = map_ret(fd[z], sd, z, i)) && ft_free_mal(map))
			return (-1);
		i = 0;
		while (i < sd->map_h[z] && map[i])
		{
			init_border_map(sd, z, i, map);
			init_int_map(sd, z, i++, map);
		}
		if (get_player_pos_and_exit(map, sd, z) < 0 && ft_free_mal(map))
			return (-1);
		ft_free_mal(map);
		z++;
	}
	return (0);
}
