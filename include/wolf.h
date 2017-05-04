/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 11:03:15 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/04 12:08:55 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <stdlib.h>
# include <stdio.h>
# include <libft.h>
# include <fcntl.h>
# include <get_next_line.h>
# include <unistd.h>
# include <math.h>
# include <SDL.h>
# include <SDL_ttf.h>
# define WIDTH 1366
# define HEIGHT 768

enum {IMG, MENU, TEXT};

typedef struct		s_parse
{
	int				fd;
	char			*line;
	int				width;
	int				height;
	int				nb;
	int				x;
	int				y;
	char			**split;
}					t_parse;

typedef struct		s_def
{
	int				**tab;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			o_dir_x;
	double			o_plane_x;
	double			plane_x;
	double			plane_y;
	double			time;
	double			o_time;
	double			m_speed;
	double			r_speed;
	double			frame_time;
	int				map_w;
	int				map_h;
}					t_def;

typedef struct		s_calc
{
	double			camera_x;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			s_dist_x;
	double			s_dist_y;
	double			d_dist_x;
	double			d_dist_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			wall_dist;
	int				test;
}					t_calc;

typedef struct		s_draw
{
	int				line_height;
	int				draw_s;
	int				draw_e;
	double			wall_x;
}					t_draw;

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Event		event_game;
	SDL_Event		event_menu;
	SDL_Renderer	*render;
	SDL_PixelFormat	*format;
	SDL_Texture		*menu[3];
	SDL_Texture		*t_sky;
	SDL_Texture		*t_floor;
	SDL_Texture		*map;
	SDL_Texture		*wall;
	SDL_Texture		*tmp_t_sky;
	Uint32			*pixels;
	SDL_Surface		*tmp_menu;
	SDL_Surface		*tmp_wall;
	SDL_Surface		*tmp_sky;
	TTF_Font		*font;
	SDL_Color		color[2];
	void			*tmp;
	int				pitch;
	int				keep_menu;
	int				keep_game;
	int				key[SDL_NUM_SCANCODES];
	int				y;
	int				width_sky;
	SDL_Rect		floor;
	SDL_Rect		postext;
	SDL_Rect		posmap;
	SDL_Rect		src;
	SDL_Rect		dest;
	SDL_Rect		floor_src;
	SDL_Rect		floor_dest;
	SDL_Rect		src_sky;
	SDL_Rect		src_sky2;
	SDL_Rect		dst_sky;
	SDL_Rect		dst_sky2;
}					t_sdl;

typedef struct		s_floor
{
	double			f_x_wall;
	double			f_y_wall;
	double			dist_wall;
	double			dist_player;
	double			current_dist;
	double			weight;	
}					t_floor;

int					**ft_create_map(char *av, t_parse parse);
void				ft_check_error(char *av, t_parse *parse);
void				ft_error(void);
void				ft_error_file(void);
void				ft_check_valid(char *line);
void				ft_check_error2(t_parse *parse);
void				ft_sdl_error(void);
void				ft_draw_saf(t_sdl *sdl);
void				ft_loop(t_def def, t_sdl *sdl);
void				ft_init_calc(t_calc *calc);
void				ft_check_wall(t_def def, t_calc *calc);
void				ft_set(t_calc *calc);
void				ft_draw(int x, t_calc calc, t_sdl *sdl);
void				ft_is_key(t_sdl *sdl, t_def *def);
void				ft_is_key2(t_sdl *sdl, t_def *def);
void				ft_init_sdl(t_sdl *sdl);
void				ft_event(t_sdl *sdl);
void				ft_draw_minimap(t_sdl *sdl, t_def def);
void				ft_init_all(t_def *def, t_sdl *sdl, t_parse *parse, \
																	char *av);
void				ft_aff(t_sdl *sdl, t_def def);
void				ft_menu(t_sdl *sdl, int select);
void				ft_text(t_sdl *sdl, int text, int select);
void				ft_text_cases(t_sdl *sdl, int text, int select);
void				ft_init_color(t_sdl *sdl);
void				ft_game(t_sdl *sdl, char *map, int select);
void				ft_select(t_sdl *sdl);
void				ft_init_42(t_def *def);
void				ft_init_1(t_def *def);
void				ft_init_2(t_def *def);
void				ft_free(t_sdl *sdl);
void				ft_key_menu(t_sdl *sdl, int *select);
void				ft_init_textures(t_sdl *sdl);

#endif
