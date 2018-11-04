/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 08:05:16 by vmartynu          #+#    #+#             */
/*   Updated: 2018/09/12 10:27:09 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	go_forward(t_sdl *sd)
{
	(sd->sounds[0]) ? Mix_PlayChannel(-1, sd->sounds[0], 0) : 0;
	if (sd->map[sd->lev][(int)(sd->cam[sd->lev].x + sd->cam[sd->lev].xdir *
		0.5)][(int)(sd->cam[sd->lev].y)] == 0)
		sd->cam[sd->lev].x += (sd->cam[sd->lev].xdir * 0.3);
	if (sd->map[sd->lev][(int)(sd->cam[sd->lev].x)][(int)(sd->cam[sd->lev].y +
		sd->cam[sd->lev].ydir * 0.5)] == 0)
		sd->cam[sd->lev].y += sd->cam[sd->lev].ydir * 0.3;
}

void	go_back(t_sdl *sd)
{
	if (sd->map[sd->lev][(int)(sd->cam[sd->lev].x - sd->cam[sd->lev].xdir *
		0.5)][(int)(sd->cam[sd->lev].y)] == 0)
		sd->cam[sd->lev].x -= sd->cam[sd->lev].xdir * 0.3;
	if (sd->map[sd->lev][(int)(sd->cam[sd->lev].x)][(int)(sd->cam[sd->lev].y -
		sd->cam[sd->lev].ydir * 0.5)] == 0)
		sd->cam[sd->lev].y -= sd->cam[sd->lev].ydir * 0.3;
}

void	turn_right(t_sdl *sd)
{
	double dirx;
	double xframe;

	dirx = sd->cam[sd->lev].xdir;
	xframe = sd->cam[sd->lev].xf;
	sd->cam[sd->lev].xdir = sd->cam[sd->lev].xdir * cos(-0.3) -
	sd->cam[sd->lev].ydir * sin(-0.3);
	sd->cam[sd->lev].ydir = dirx * sin(-0.3) +
	sd->cam[sd->lev].ydir * cos(-0.3);
	sd->cam[sd->lev].xf = sd->cam[sd->lev].xf * cos(-0.3) -
	sd->cam[sd->lev].yf * sin(-0.3);
	sd->cam[sd->lev].yf = xframe * sin(-0.3) + sd->cam[sd->lev].yf * cos(-0.3);
}

void	turn_left(t_sdl *sd)
{
	double dirx;
	double xframe;

	dirx = sd->cam[sd->lev].xdir;
	xframe = sd->cam[sd->lev].xf;
	sd->cam[sd->lev].xdir = sd->cam[sd->lev].xdir * cos(0.3) -
	sd->cam[sd->lev].ydir * sin(0.3);
	sd->cam[sd->lev].ydir = dirx * sin(0.3) + sd->cam[sd->lev].ydir * cos(0.3);
	sd->cam[sd->lev].xf = sd->cam[sd->lev].xf * cos(0.3) -
	sd->cam[sd->lev].yf * sin(0.3);
	sd->cam[sd->lev].yf = xframe * sin(0.3) + sd->cam[sd->lev].yf * cos(0.3);
}
