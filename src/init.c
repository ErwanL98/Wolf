/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 14:33:06 by ele-cren          #+#    #+#             */
/*   Updated: 2017/04/25 11:25:27 by ele-cren         ###   ########.fr       */
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

void	ft_init_all(t_def *def, t_sdl *sdl, t_parse *parse,  char *av)
{
	sdl->keep_game = 1;
	ft_check_error(av, parse);
	def->tab = ft_create_map(av, *parse);
	def->map_w = parse->width * 14;
	def->map_h = parse->height * 14;
	sdl->posmap.x = 0;
	sdl->posmap.y = 0;
	sdl->posmap.w = def->map_w;
	sdl->posmap.h = def->map_h;
	if ((sdl->map = SDL_CreateTexture(sdl->render, SDL_PIXELFORMAT_RGBA8888, \
				SDL_TEXTUREACCESS_STREAMING, def->map_w, def->map_h)) == NULL)
		ft_sdl_error();
	if ((sdl->tmp_wall = SDL_LoadBMP("./img/wall.bmp")) == NULL)
		ft_sdl_error();
	if ((sdl->wall = SDL_CreateTextureFromSurface(sdl->render, \
					sdl->tmp_wall)) == NULL)
		ft_sdl_error();
	SDL_FreeSurface(sdl->tmp_wall);
	def->r_speed = 2.5;
	sdl->y = 0;
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
