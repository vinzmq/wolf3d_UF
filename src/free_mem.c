/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:59:34 by vmartynu          #+#    #+#             */
/*   Updated: 2018/09/11 11:04:22 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			release_textures_n_maps(t_sdl *sd)
{
	int			i;

	i = 0;
	while (i < 7)
	{
		SDL_FreeSurface(sd->textures[i]);
		i++;
	}
}

void			ft_free_map(t_sdl *sd)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j < LEVELS)
	{
		i = 0;
		while (i < sd->map_h[j])
		{
			if (sd->map[j] && sd->map[j][i])
				free(sd->map[j][i]);
			i++;
		}
		if (sd->map[j])
			free(sd->map[j]);
		j++;
	}
}

int				ft_free_mal(char **strfree)
{
	int	i;

	i = 0;
	if (strfree)
	{
		while (strfree[i])
		{
			ft_strdel(&strfree[i]);
			i++;
		}
		free(strfree);
	}
	return (1);
}
