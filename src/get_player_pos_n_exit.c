/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos_n_exit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 08:22:35 by vmartynu          #+#    #+#             */
/*   Updated: 2018/09/11 10:18:49 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		set_cam_dir(t_sdl *sd, int i, int j, int z)
{
	sd->cam[z].x = (double)i + 0.5;
	sd->cam[z].y = (double)j + 0.5;
	sd->cam[z].xdir = -1;
	sd->cam[z].ydir = 0;
	sd->cam[z].xf = 0;
	sd->cam[z].yf = 0.66;
}

static int		exits(int z, t_sdl *sd, int i, int j)
{
	sd->exx[z] = (double)i;
	sd->exy[z] = (double)j;
	return (1);
}

static int		map_i_j(t_sdl *sd, int i, char **map, int z)
{
	int j;
	int flag;
	int ex;

	ex = 0;
	flag = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == 'p' && sd->cam[z].x == 0 && sd->cam[z].y == 0)
		{
			flag++;
			if (i == 0 || (i == sd->map_h[sd->lev] - 1) || j == 0 ||
				j == (int)ft_strlen(map[i]) - 1)
			{
				ft_putstr("Player is on the border of the map\n");
				return (-1);
			}
			set_cam_dir(sd, i, j, z);
		}
		if (map[i][j] == '7' && ex == 0)
			ex = exits(z, sd, i, j);
		j++;
	}
	return (flag);
}

int				get_player_pos_and_exit(char **map, t_sdl *sd, int z)
{
	int		i;
	int		j;
	int		flag;

	flag = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		if ((flag = map_i_j(sd, i, map, z) < 0))
			return (-1);
		i++;
	}
	if (flag == 0 && sd->cam[z].x == 0 && sd->cam[z].y == 0)
	{
		ft_putstr("No player in map\n");
		return (-1);
	}
	return (0);
}
