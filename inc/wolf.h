/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:05:40 by vmartynu          #+#    #+#             */
/*   Updated: 2018/08/02 18:53:29 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WOLF_H
# define FT_WOLF_H

# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>
# include <OpenCL/opencl.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include "../libft/Libft/libft.h"
# include <errno.h>
# include <time.h>

# define LEVELS 3
# define WIDTH 600
# define HEIGHT 600

typedef double			t_vector __attribute__((vector_size(sizeof(double)*4)));

typedef struct			s_camera
{
	double				x;
	double				y;
	double				xdir;
	double				ydir;
	double				xf;
	double				yf;
}						t_camera;

typedef struct			s_dir
{
	double				x;
	double				y;
}						t_dir;

typedef struct			s_sdl
{
	SDL_Window			*window;
	SDL_Surface			*screen;
	SDL_Event			event;
	int					map_w[3];
	int					map_h[3];
	double				ray_pos;
	double				ray_dirx;
	double				ray_diry;
	double				flrx;
	double				flry;
	int					tex;
	t_camera			cam[3];
	SDL_Surface			*textures[7];
	Mix_Music			*muz;
	Mix_Chunk			*sounds[3];
	int					**map[3];
	int					lev;
	double				exx[3];
	double				exy[3];
	unsigned	char	*ptr;
	int					x_texture;
	int					y_texture;
	int					xf_texture;
	int					yf_texture;
	double				scale;
	int					wall_height;
	double				curdist;
	double				dist_wall;
	double				offset;
	int					mapx;
	int					mapy;
	double				tox;
	double				toy;
	double				dx;
	double				dy;
	double				dist;
	int					stepx;
	int					stepy;
	double				inters;
	int					side;
	int					is_running;
}						t_sdl;

int						ft_int_strdel(char **str);
void					go_forward(t_sdl *sd);
void					go_back(t_sdl *sd);
void					turn_right(t_sdl *sd);
void					turn_left(t_sdl *sd);
int						read_map(t_sdl *sd, int *fd);
void					dda_algorithm(t_sdl *sd);
void					check_wall_d(t_sdl *sd);
char					**map_ret(int fd, t_sdl *sd, int z, int i);
void					find_walls(t_sdl *sd, int x, int *begin, int *end);
t_vector				set_wallcolor(t_sdl *sd, int num_tex);
t_vector				set_floorcolor(t_sdl *sd, int num_tex);
void					draw_scene(t_sdl *sd);
int						get_player_pos_and_exit(char **map, t_sdl *sd, int z);
void					putpixel(t_sdl *sd, int x, int y, t_vector color);
void					render(t_sdl *sd);
int						ft_chartoi(const char c);
void					ft_free_map(t_sdl *sd);
int						ft_free_mal(char **strfree);
void					release_textures_n_maps(t_sdl *sd);
void					loop(t_sdl *sd);

#endif
