/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 08:52:50 by vmartynu          #+#    #+#             */
/*   Updated: 2018/09/11 10:24:21 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		draw_walls(t_sdl *sd, int x, int y, int end)
{
	int				d;
	int				i;
	t_vector		color;

	i = 0;
	while (y < end)
	{
		d = y * 256 - HEIGHT  * 128 + sd->wall_height * 128;
		sd->y_texture = ((d * 512) / sd->wall_height) / 512;
		if (sd->tex == 1)
			color = set_wallcolor(sd, 0 * sd->lev);
		else if (sd->tex == 2)
			color = set_wallcolor(sd, 1 * sd->lev);
		else if (sd->tex == 3)
			color = set_wallcolor(sd, 2 * sd->lev);
		else if (sd->tex == 4)
			color = set_wallcolor(sd, 3 * sd->lev);
		else
			color = set_wallcolor(sd, 9);
		if (sd->map[sd->lev][sd->mapx][sd->mapy] == 7)
			color = set_wallcolor(sd, 6);
		putpixel(sd, x, y, color);
		y++;
	}
}

// static void		draw_floor_and_ceil(t_sdl *sd, int x, int y)
// {
// 	double			cflrx;
// 	double			cflry;
// 	t_vector		color;

// 	while (y < HEIGHT)
// 	{
// 		sd->curdist = 256 / (2.0 * y - HEIGHT);
// 		sd->scale = (sd->curdist) / (sd->dist);
// 		cflrx = sd->scale * sd->flrx + (1.0 - sd->scale) * sd->cam[sd->lev].x;
// 		cflry = sd->scale * sd->flry + (1.0 - sd->scale) * sd->cam[sd->lev].y;
// 		sd->xf_texture = (int)(cflrx * 512) % 256;
// 		sd->yf_texture = (int)(cflry * 512) % 256;
// 		color = set_floorcolor(sd, 4);
// 		putpixel(sd, x, y, color);
// 		color = set_floorcolor(sd, 5);
// 		putpixel(sd, x, HEIGHT - y, color);
// 		y++;
// 	}
// }

void			draw_scene(t_sdl *sd)
{
	int			end;
	int			x;
	int			y;

	x = 0;
	while (x < WIDTH)
	{
		find_walls(sd, x, &y, &end);
		draw_walls(sd, x, y, end);
		check_wall_d(sd);
		if (end < 0)
			end = HEIGHT;
		y = end;
		//draw_floor_and_ceil(sd, x, y);
		x++;
	}
}
