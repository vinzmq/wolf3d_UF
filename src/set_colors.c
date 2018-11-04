/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 08:52:30 by vmartynu          #+#    #+#             */
/*   Updated: 2018/09/11 10:08:58 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_vector		set_wallcolor(t_sdl *sd, int num_tex)
{
	t_vector		color;
	int				i;

	if (num_tex != 9)
	{
		i = sd->textures[num_tex]->pitch * sd->y_texture + sd->x_texture *
			sd->textures[num_tex]->format->BytesPerPixel;
		sd->ptr = (unsigned char*)&sd->textures[num_tex]->pixels[i];
		color[2] = (double)sd->ptr[i++] / 255;
		color[1] = (double)sd->ptr[i++] / 255;
		color[0] = (double)sd->ptr[i++] / 255;
	}
	else
	{
		color[2] = 0;
		color[1] = 0;
		color[0] = 0;
	}
	return (color);
}

t_vector		set_floorcolor(t_sdl *sd, int num_tex)
{
	t_vector		color;
	int				i;

	if (num_tex != 9)
	{
		i = sd->textures[num_tex]->pitch * sd->yf_texture + sd->xf_texture *
			sd->textures[num_tex]->format->BytesPerPixel;
		sd->ptr = (unsigned char*)&sd->textures[num_tex]->pixels[i];
		color[2] = (double)sd->ptr[i++] / 255;
		color[1] = (double)sd->ptr[i++] / 255;
		color[0] = (double)sd->ptr[i++] / 255;
	}
	else
	{
		color[2] = 0;
		color[1] = 0;
		color[0] = 0;
	}
	return (color);
}
