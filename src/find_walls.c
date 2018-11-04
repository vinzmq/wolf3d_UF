/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 08:51:58 by vmartynu          #+#    #+#             */
/*   Updated: 2018/09/11 11:01:09 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		find_walls(t_sdl *sd, int x, int *begin, int *end)
{
	sd->ray_pos = 2 * x / (double)(WIDTH) - 1;
	sd->ray_dirx = sd->cam[sd->lev].xdir + sd->cam[sd->lev].xf * sd->ray_pos;
	sd->ray_diry = sd->cam[sd->lev].ydir + sd->cam[sd->lev].yf * sd->ray_pos;
	sd->mapx = (int)sd->cam[sd->lev].x;
	sd->mapy = (int)sd->cam[sd->lev].y;
	sd->dx = sqrt(1 + (sd->ray_diry * sd->ray_diry) /
	(sd->ray_dirx * sd->ray_dirx));
	sd->dy = sqrt(1 + (sd->ray_dirx * sd->ray_dirx) /
	(sd->ray_diry * sd->ray_diry));
	dda_algorithm(sd);
	if ((*begin = -sd->wall_height / 2 + HEIGHT / 2) < 0)
		*begin = 0;
	if ((*end = sd->wall_height / 2 + HEIGHT / 2) >= HEIGHT)
		*end = HEIGHT - 1;
	sd->x_texture = (int)(sd->offset * 512);
	if (sd->side == 0 && sd->ray_dirx > 0)
		sd->x_texture = 512 - sd->x_texture - 1;
	if (sd->side == 1 && sd->ray_diry < 0)
		sd->x_texture = 512 - sd->x_texture - 1;
}
