/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pxl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:22:13 by vmartynu          #+#    #+#             */
/*   Updated: 2018/09/11 10:17:14 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		toint(double x)
{
	int	c;

	if (x < 0)
		x = 0;
	else
	{
		if (x > 1)
			x = 1;
	}
	c = (int)(pow(x, 1 / 2.2) * 255 + 0.5);
	return (c);
}

void			putpixel(t_sdl *sd, int x, int y, t_vector color)
{
	unsigned char	*ptr;
	int				i;

	i = 0;
	i = x * 4 + y * sd->screen->pitch;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		ptr = (unsigned char*)sd->screen->pixels;
		ptr[i++] = toint(color[2]);
		ptr[i++] = toint(color[1]);
		ptr[i++] = toint(color[0]);
	}
}
