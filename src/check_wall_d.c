/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:06:11 by vmartynu          #+#    #+#             */
/*   Updated: 2018/09/11 11:03:29 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	check_wall_d(t_sdl *sd)
{
	if (sd->side == 0 && sd->ray_dirx > 0)
	{
		sd->flrx = sd->mapx;
		sd->flry = sd->mapy + sd->offset;
	}
	else if (sd->side == 0 && sd->ray_dirx < 0)
	{
		sd->flrx = sd->mapx + 1.0;
		sd->flry = sd->mapy + sd->offset;
	}
	else if (sd->side == 1 && sd->ray_diry > 0)
	{
		sd->flrx = sd->mapx + sd->offset;
		sd->flry = sd->mapy;
	}
	else
	{
		sd->flrx = sd->mapx + sd->offset;
		sd->flry = sd->mapy + 1.0;
	}
}
