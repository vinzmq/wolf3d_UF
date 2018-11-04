/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:40:27 by vmartynu          #+#    #+#             */
/*   Updated: 2018/09/12 13:40:29 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			loop(t_sdl *sd)
{
	const Uint8	*keyboardstate;

	keyboardstate = SDL_GetKeyboardState(NULL);
	while (sd->is_running && sd->lev < LEVELS)
	{
		while (SDL_PollEvent(&sd->event))
		{
			if (sd->event.type == SDL_QUIT)
				sd->is_running = 0;
			if (sd->event.type == SDL_KEYDOWN && sd->event.key.keysym.sym ==
			SDLK_ESCAPE)
				sd->is_running = 0;
			if (keyboardstate[SDL_SCANCODE_RIGHT])
				turn_right(sd);
			if (keyboardstate[SDL_SCANCODE_LEFT])
				turn_left(sd);
			if (keyboardstate[SDL_SCANCODE_UP])
				go_forward(sd);
			if (keyboardstate[SDL_SCANCODE_DOWN])
				go_back(sd);
		}
		render(sd);
	}
}
