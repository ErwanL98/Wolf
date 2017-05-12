/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 14:33:06 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/12 16:06:21 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_init_calc(t_calc *calc)
{
	calc->hit = 0;
	calc->map_x = (int)calc->ray_pos_x;
	calc->map_y = (int)calc->ray_pos_y;
	calc->d_dist_x = sqrt(1 + (calc->ray_dir_y * calc->ray_dir_y) / \
			(calc->ray_dir_x * calc->ray_dir_x));
	calc->d_dist_y = sqrt(1 + (calc->ray_dir_x * calc->ray_dir_x) / \
			(calc->ray_dir_y * calc->ray_dir_y));
}

void	ft_init_rect(t_sdl *sdl, t_def *def)
{
	sdl->dst[DMAP].x = 0;
	sdl->dst[DMAP].y = 0;
	sdl->dst[DMAP].w = def->map_w;
	sdl->dst[DMAP].h = def->map_h;
	sdl->src[SSKY].x = 684;
	sdl->src[SSKY].y = 0;
	sdl->src[SSKY].w = WIDTH;
	sdl->src[SSKY].h = HEIGHT;
	sdl->dst[DSKY].x = 0;
	sdl->dst[DSKY].y = 0;
	sdl->dst[DSKY].w = WIDTH;
	sdl->dst[DSKY].h = HEIGHT;
	sdl->dst[DSHOTGUN].x = WIDTH / 2 - 105;
	sdl->dst[DSHOTGUN].y = HEIGHT - (sdl->dst[DSHOTGUN].h);
	sdl->dst[DWEAPONS].x = WIDTH - sdl->dst[DWEAPONS].w;
	sdl->dst[DWEAPONS].y = HEIGHT - sdl->dst[DWEAPONS].h;
	sdl->dst[DGUN].x = WIDTH / 2 - 105;
	sdl->dst[DGUN].y = HEIGHT - (sdl->dst[DGUN].h);
}

void	ft_init_textures(t_sdl *sdl, t_def *def)
{
	if ((sdl->game[TMAP] = SDL_CreateTexture(sdl->render, \
			SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, \
									def->map_w, def->map_h)) == NULL)
		ft_sdl_error();
	sdl->game[TWALL] = ft_create_texture("./img/wall.bmp", sdl, 0);
	sdl->game[TSHOTGUN] = ft_create_texture("./img/shotgun1.bmp", sdl, 1);
	SDL_QueryTexture(sdl->game[TSHOTGUN], NULL, NULL, \
			&sdl->dst[DSHOTGUN].w, &sdl->dst[DSHOTGUN].h);
	sdl->game[TWEAPONS] = ft_create_texture("./img/weapons.bmp", sdl, 0);
	SDL_QueryTexture(sdl->game[TWEAPONS], NULL, NULL, \
			&sdl->dst[DWEAPONS].w, &sdl->dst[DWEAPONS].h);
	sdl->game[TGUN] = ft_create_texture("./img/gun1.bmp", sdl, 1);
	SDL_QueryTexture(sdl->game[TGUN], NULL, NULL, \
			&sdl->dst[DGUN].w, &sdl->dst[DGUN].h);
}

void	ft_init(t_def *def, t_sdl *sdl, t_parse *parse,  char *av)
{
	sdl->weapon = 1;
	def->w_time = 0;
	sdl->keep_game = 1;
	ft_check_error(av, parse);
	def->tab = ft_create_map(av, *parse);
	def->map_w = parse->width * 14;
	def->map_h = parse->height * 14;
	ft_init_textures(sdl, def);
	ft_init_rect(sdl, def);
	def->r_speed = 1.25;
	sdl->y = 0;
	ft_memset(&sdl->in, 0, sizeof(sdl->in));
}

void	ft_init_color(t_sdl *sdl)
{
	sdl->color[0].r = 0;
	sdl->color[0].g = 0;
	sdl->color[0].b = 0;
	sdl->color[1].r = 225;
	sdl->color[1].g = 225;
	sdl->color[1].b = 225;
}
