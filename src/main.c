/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 10:00:31 by vmartynu          #+#    #+#             */
/*   Updated: 2018/09/12 10:36:46 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		check_textures(t_sdl *sd)
{
	int		i;

	i = 0;
	if (!sd->textures[1] || !sd->textures[2] || !sd->textures[3] ||
		!sd->textures[4] || !sd->textures[5] || !sd->textures[6] ||
		!sd->textures[0])
	{
		ft_putstr("One of textures is missing!\n");
		return (-1);
	}
	return (0);
}

static int		init_textures(t_sdl *sd)
{
	int		ret;

	sd->textures[0] = SDL_LoadBMP("./textures/wall1.bmp");
	sd->textures[1] = SDL_LoadBMP("./textures/wall2.bmp");
	sd->textures[2] = SDL_LoadBMP("./textures/wall3.bmp");
	sd->textures[3] = SDL_LoadBMP("./textures/wall4.bmp");
	sd->textures[4] = SDL_LoadBMP("./textures/stone1.bmp");
	sd->textures[5] = SDL_LoadBMP("./textures/ceiling_decoration_1.bmp");
	sd->textures[6] = SDL_LoadBMP("./textures/chaos1.bmp");
	if ((ret = check_textures(sd)) < 0)
		return (-1);
	SDL_LockSurface(sd->textures[1]);
	SDL_LockSurface(sd->textures[2]);
	SDL_LockSurface(sd->textures[3]);
	SDL_LockSurface(sd->textures[4]);
	SDL_LockSurface(sd->textures[5]);
	SDL_LockSurface(sd->textures[6]);
	SDL_LockSurface(sd->textures[0]);
	return (ret);
}

int				init_sdl(t_sdl *sd)
{
	int		ret;

	ret = 0;
	sd->muz = Mix_LoadMUS("./waves/imperial.wav");
	sd->sounds[0] = Mix_LoadWAV("./waves/blaster.wav");
	if (!sd->muz || !sd->sounds[0])
		ret = -1;
	sd->lev = 0;
	sd->is_running = 1;
	sd->window = SDL_CreateWindow("wolf3d",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	WIDTH, HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	sd->screen = SDL_GetWindowSurface(sd->window);
	SDL_memset(sd->screen->pixels, 0, sd->screen->h * sd->screen->pitch);
	if (ret == 0)
		ret = init_textures(sd);
	return (ret);
}

int				read_fd(int *fd)
{
	t_sdl		sd;
	int			ret;

	SDL_Init(SDL_INIT_EVERYTHING);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	ret = init_sdl(&sd);
	(sd.muz) ? Mix_PlayMusic(sd.muz, -1) : 0;
	if (ret == 0)
		ret = read_map(&sd, fd);
	if (ret == 0)
		loop(&sd);
	SDL_FreeSurface(sd.screen);
	Mix_FreeChunk(sd.sounds[0]);
	Mix_FreeMusic(sd.muz);
	Mix_CloseAudio();
	ft_free_map(&sd);
	release_textures_n_maps(&sd);
	return (ret);
}

int				main(int argc, char **argv)
{
	int				fd[3];

	if (argc == 1)
	{
		fd[0] = open("./levels/level_1", O_RDWR);
		fd[1] = open("./levels/level_2", O_RDWR);
		fd[2] = open("./levels/level_3", O_RDWR);
		if (fd[0] > 0 && fd[1] > 0 && fd[2] > 0 && argv[0])
			read_fd(fd);
		else
		{
			ft_putstr("restore levels...\n");
			ft_putstr(strerror(errno));
			ft_putchar('\n');
		}
	}
	else
		ft_putstr("usage: ./wolf3d\n");
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	return (0);
}
