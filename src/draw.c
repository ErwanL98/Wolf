/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:33:20 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/04 12:43:37 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_draw(int x, t_calc calc, t_sdl *sdl)
{
	t_draw	draw;

	if (calc.side == 0)
		draw.wall_x = calc.ray_pos_y + calc.wall_dist * calc.ray_dir_y;
	else
		draw.wall_x = calc.ray_pos_x + calc.wall_dist * calc.ray_dir_x;
	draw.wall_x = draw.wall_x - (int)draw.wall_x;
	SDL_QueryTexture(sdl->wall, NULL, NULL, &sdl->src.w, &sdl->src.h);
	sdl->src.x = draw.wall_x * sdl->src.w;
	sdl->src.w = 1;
	sdl->src.y = 0;
	draw.line_height = (int)HEIGHT / calc.wall_dist;
	draw.draw_s = -draw.line_height / 2 + HEIGHT / 2 + sdl->y;
	draw.draw_e = draw.line_height / 2 + HEIGHT / 2 + sdl->y;
	sdl->dest.x = x;
	sdl->dest.h = draw.draw_e - draw.draw_s;
	sdl->dest.y = draw.draw_s;
	sdl->dest.w = 1;
	SDL_RenderCopy(sdl->render, sdl->wall, &sdl->src, &sdl->dest);
}

/*void	ft_draw_caf(t_calc calc, t_sdl *sdl, t_draw *draw, t_def def)
{
	t_floor	floor;
	int		y;

	if (calc.side == 0 && calc.ray_dir_x > 0)
	{
		floor.f_x_wall = calc.map_x;
		floor.f_y_wall = calc.map_y + draw->wall_x;
	}
	else if (calc.side == 0 && calc.ray_dir_x < 0)
	{
		floor.f_x_wall = calc.map_x + 1.0;
		floor.f_y_wall = calc.map_y + draw->wall_x;
	}
	if (calc.side == 1 && calc.ray_dir_y > 0)
	{
		floor.f_x_wall = calc.map_x + draw->wall_x;
		floor.f_y_wall = calc.map_y;
	}
	else if (calc.side == 1 && calc.ray_dir_y < 0)
	{
		floor.f_x_wall = calc.map_x + draw->wall_x;
		floor.f_y_wall = calc.map_y + 1.0;
	}
	floor.dist_wall = calc.wall_dist;
	draw->draw_e = (draw->draw_e < 0) ? HEIGHT : draw->draw_e;
	y = draw->draw_e + 1;
	while (y < HEIGHT)
	{

	}
}*/

void	ft_draw_minimap(t_sdl *sdl, t_def def)
{
	int		x;
	int		y;
	Uint32	color[3];

	color[0] = SDL_MapRGBA(sdl->format, 67, 67, 67, 255);
	color[1] = SDL_MapRGBA(sdl->format, 215, 215, 215, 255);
	color[2] = SDL_MapRGBA(sdl->format, 174, 4, 4, 255);
	SDL_LockTexture(sdl->map, NULL, &sdl->tmp, &sdl->pitch);
	sdl->pixels = sdl->tmp;
	y = -1;
	while (++y < def.map_h)
	{
		x = -1;
		while (++x < def.map_w)
		{
			if (def.tab[y / 14][x / 14] == 1)
				sdl->pixels[x + (y * def.map_w)] = color[0];
			else if (y / 14 == (int)def.pos_y && x / 14 == (int)def.pos_x)
				sdl->pixels[x + (y * def.map_w)] = color[2];
			else if (def.tab[y / 14][x / 14] == 0)
				sdl->pixels[x + (y * def.map_w)] = color[1];
		}
	}
	SDL_UnlockTexture(sdl->map);
}

void	ft_draw_saf(t_sdl *sdl)
{
	int		x;
	int		y;
	Uint32	color;

	if ((sdl->tmp_sky = SDL_LoadBMP("./img/sky2.bmp")) == NULL)
		ft_sdl_error();
	if ((sdl->t_sky = SDL_CreateTextureFromSurface(sdl->render, sdl->tmp_sky)) == NULL)
		ft_sdl_error();
	SDL_QueryTexture(sdl->t_sky, NULL, NULL, &sdl->width_sky, NULL);
	SDL_FreeSurface(sdl->tmp_sky);
	y = -1;
	color = SDL_MapRGBA(sdl->format, 64, 64, 64, 255);
	SDL_LockTexture(sdl->t_floor, NULL, &sdl->tmp, &sdl->pitch);
	sdl->pixels = sdl->tmp;
	while (++y < HEIGHT * 2)
	{
		x = -1;
		while (++x < WIDTH)
			sdl->pixels[x + (y * WIDTH)] = color;
	}
	SDL_UnlockTexture(sdl->t_floor);
}
