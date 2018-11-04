/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:10:58 by vmartynu          #+#    #+#             */
/*   Updated: 2018/09/12 10:28:23 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			render(t_sdl *sd)
{
	SDL_memset(sd->screen->pixels, 0, sd->screen->h * sd->screen->pitch);
	draw_scene(sd);
	SDL_UpdateWindowSurface(sd->window);
	if (sqrt(pow((sd->cam[sd->lev].x - sd->exx[sd->lev]), 2) +
		pow((sd->cam[sd->lev].y - sd->exy[sd->lev]), 2)) < 1.5)
	{
		sd->lev++;
		if (sd->lev < LEVELS)
			ft_putstr("next level...");
		else
			ft_putstr("You WIN!!!!!!!!!!!");
	}
}
