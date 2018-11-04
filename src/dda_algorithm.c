/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 08:57:10 by vmartynu          #+#    #+#             */
/*   Updated: 2018/09/11 10:46:25 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		intersect_wall(t_sdl *sd)
{
	int			wall_inters;

	wall_inters = 0;
	while (wall_inters == 0)
	{
		if (sd->tox < sd->toy)
		{
			sd->tox = sd->tox + sd->dx;
			sd->mapx = sd->mapx + sd->stepx;
			sd->side = 0;
			sd->offset = sd->mapx % HEIGHT;
		}
		else
		{
			sd->toy = sd->toy + sd->dy;
			sd->mapy = sd->mapy + sd->stepy;
			sd->side = 1;
			sd->offset = sd->mapy % HEIGHT;
		}
		if (sd->map[sd->lev][sd->mapx][sd->mapy] > 0)
			wall_inters = 1;
	}
}

static void		get_compass_texture(t_sdl *sd)
{
	if (sd->side == 0)
	{
		sd->dist = (sd->mapx - sd->cam[sd->lev].x + (1 - sd->stepx) / 2) /
		sd->ray_dirx;
		sd->inters = sd->cam[sd->lev].y + sd->dist * sd->ray_diry;
		sd->offset = sd->inters - (int)sd->inters;
		if (sd->ray_dirx > 0)
			sd->tex = 1;
		else
			sd->tex = 2;
	}
	else
	{
		sd->dist = (sd->mapy - sd->cam[sd->lev].y + (1 - sd->stepy) / 2) /
		sd->ray_diry;
		sd->inters = sd->cam[sd->lev].x + sd->dist * sd->ray_dirx;
		sd->offset = sd->inters - (int)sd->inters;
		if (sd->ray_diry > 0)
			sd->tex = 3;
		else
			sd->tex = 4;
	}
}

void			dda_algorithm(t_sdl *sd)
{
	sd->inters = 0;
	if (sd->ray_dirx < 0 && (sd->stepx = -1))
		sd->tox = (sd->cam[sd->lev].x - sd->mapx) * sd->dx;
	else
	{
		sd->stepx = 1;
		sd->tox = (sd->mapx + 1.0 - sd->cam[sd->lev].x) * sd->dx;
	}
	if (sd->ray_diry < 0 && (sd->stepy = -1))
		sd->toy = (sd->cam[sd->lev].y - sd->mapy) * sd->dy;
	else
	{
		sd->stepy = 1;
		sd->toy = (sd->mapy + 1.0 - sd->cam[sd->lev].y) * sd->dy;
	}
	intersect_wall(sd);
	get_compass_texture(sd);
	sd->wall_height = HEIGHT / sd->dist * 0.5;
}
