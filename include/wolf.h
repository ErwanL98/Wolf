/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 11:03:15 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/18 16:46:14 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <stdlib.h>
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
enum {TSKY, TFLOOR, TWALL, TMAP, TFPS, TSHOTGUN, TWEAPONS, TGUN, TGUN2, \
	TSHOTGUN2, TWALLB, GARG, RGARG, TLIFE};
enum {TTF, TEXTURE};
enum {DMAP, DTEXT, DFLOOR, DWALL, DSKY, DFPS, DWEAPONS, DGUN, DSHOTGUN, DLIFE};
enum {SWALL, SSKY};

typedef struct		s_parse
{
	int				i;
	char			*test;
	int				fd;
	char			*line;
	int				width;
	int				height;
	int				nb;
	int				count;
	int				x;
	int				y;
	char			**split;
	int				**tab;
}					t_parse;

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

typedef	struct		s_garg
{
	double			pos_x;
	double			pos_y;
	double			test_x;
	double			test_y;
	int				i;
	int				x;
	int				f_x;
	int				l_x;
	int				dead;
	SDL_Rect		rect;
	SDL_Rect		drect;
	int				disp;
	double			dist;
	t_calc			calc;
	int				life;
	int				disp_life;
	double			time;
}					t_garg;

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
	double			w_time;
	double			m_speed;
	double			r_speed;
	double			frame_time;
	int				map_w;
	int				map_h;
	int				weapon;
	int				fire;
	t_garg			garg;
	double			x1;
	double			y1;
}					t_def;

typedef struct		s_draw
{
	int				line_height;
	int				draw_s;
	int				draw_e;
	double			wall_x;
}					t_draw;

typedef struct		s_input
{
	char			key[SDL_NUM_SCANCODES];
	int				x_rel;
	int				y_rel;
	char			button[8];
}					t_input;

typedef struct		s_game
{
	int				pos_x;
	int				pos_y;
	int				breakable;
}					t_game;

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Event		event_game;
	SDL_Event		event_menu;
	SDL_Renderer	*render;
	SDL_PixelFormat	*format;
	SDL_Texture		*menu[3];
	SDL_Texture		*game[14];
	SDL_Surface		*load[2];
	TTF_Font		*font;
	TTF_Font		*font2;
	SDL_Color		color[2];
	void			*tmp;
	int				pitch;
	Uint32			*pixels;
	int				keep_menu;
	int				keep_game;
	int				y;
	int				width_sky;
	SDL_Rect		dst[10];
	SDL_Rect		src[2];
	t_input			in;
	t_game			wallbreak;
}					t_sdl;

void				ft_error(void);
void				ft_error_file(void);
void				ft_sdl_error(void);
void				ft_draw_saf(t_sdl *sdl);
void				ft_loop(t_def *def, t_sdl *sdl);
void				ft_init_calc(t_calc *calc);
void				ft_check_wall(t_def def, t_calc *calc);
void				ft_set(t_calc *calc);
void				ft_draw(int x, t_calc calc, t_sdl *sdl, t_def def);
void				ft_power(t_sdl *sdl, t_def *def);
void				ft_move_bf(t_sdl *sdl, t_def *def);
void				ft_move_rl(t_sdl *sdl, t_def *def);
void				ft_cam_r(t_sdl *sdl, t_def *def);
void				ft_cam_lud(t_sdl *sdl, t_def *def);
void				ft_init_sdl(t_sdl *sdl);
void				ft_event(t_sdl *sdl);
void				ft_draw_minimap(t_sdl *sdl, t_def def);
void				ft_init(t_def *def, t_sdl *sdl, t_parse *parse, \
		char *av);
void				ft_display(t_sdl *sdl, t_def *def);
void				ft_display_guns(t_sdl *sdl, t_def *def);
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
void				ft_init_saf(t_sdl *sdl);
void				ft_mouse1(t_sdl *sdl, t_def *def);
void				ft_mouse2(t_sdl *sdl, t_def *def);
void				ft_init_rect(t_sdl *sdl, t_def *def);
SDL_Texture			*ft_create_texture(char *str, t_sdl *sdl, int mod);
void				ft_fps(t_sdl *sdl, t_def *def);
void				ft_init_textures(t_sdl *sdl, t_def *def);
void				ft_freegame(t_sdl *sdl, t_def *def, t_parse parse);
void				ft_check_map(char *map, t_parse *parse);
void				ft_check_line(char *line, int *count);
int					**ft_create_tab(char *map, t_parse parse);
void				ft_test(char *map, t_parse parse);
void				ft_disp_garg(t_def *def, t_sdl *sdl, t_calc calc);
void				ft_move_l(t_sdl *sdl, t_def *def);
void				ft_move_b(t_sdl *sdl, t_def *def);
void				ft_move_f(t_sdl *sdl, t_def *def);
void				ft_move_r(t_sdl *sdl, t_def *def);
void				ft_init_garg(t_def *def, t_sdl *sdl);
void				ft_init_draw(t_calc calc, t_sdl *sdl, t_draw *draw, \
																t_def def);
void				ft_draw_life(t_def def, t_sdl *sdl);
void				ft_copy(t_sdl *sdl, t_def *def);
void				ft_destroy_garg(t_def *def, t_sdl *sdl);

#endif
