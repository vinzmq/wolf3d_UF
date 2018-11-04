/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ret.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 08:27:59 by vmartynu          #+#    #+#             */
/*   Updated: 2018/09/11 10:15:22 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		count_line(char *line, t_sdl *sd, int z)
{
	int			lenght;

	lenght = ft_strlen(line);
	if (sd->map_w[z] < lenght)
		sd->map_w[z] = lenght;
}

static void		collect_exits(char *map)
{
	int			i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'e')
			map[i] = '7';
		i++;
	}
}

static void		make_level(t_sdl *sd, int z)
{
	int			i;
	int			j;

	i = 0;
	sd->map[z] = (int **)malloc(sizeof(int *) * sd->map_h[z]);
	while (i < sd->map_h[z])
		sd->map[z][i++] = (int *)malloc(sizeof(int) * sd->map_w[z]);
	i = 0;
	while (i < sd->map_h[z])
	{
		j = 0;
		while (j < sd->map_w[z])
		{
			sd->map[z][i][j] = 1;
			j++;
		}
		i++;
	}
}

char			**map_ret(int fd, t_sdl *sd, int z, int i)
{
	char		*line;
	char		**ret;
	char		*tmp;
	char		*level;

	i = 0;
	line = NULL;
	tmp = ft_strdup("");
	while (get_next_line(fd, &line))
	{
		count_line(line, sd, z);
		level = ft_strjoin(tmp, line);
		ft_strdel(&tmp);
		ft_strdel(&line);
		tmp = ft_strjoin(level, "\n");
		ft_strdel(&level);
		sd->map_h[z]++;
	}
	if ((sd->map_h[z] < 3 || sd->map_w[z] < 3) && ft_int_strdel(&tmp))
		return (NULL);
	collect_exits(tmp);
	ret = ft_strsplit(tmp, '\n');
	ft_strdel(&tmp);
	make_level(sd, z);
	return (ret);
}
