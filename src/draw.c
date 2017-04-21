/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:33:20 by ele-cren          #+#    #+#             */
/*   Updated: 2017/04/21 14:56:28 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_draw(int x, t_calc calc, t_sdl *sdl)
{
	t_draw	draw;
	double		wall_x;

	if (calc.side == 0)
		wall_x = calc.ray_pos_y + calc.wall_dist * calc.ray_dir_y;
	else
		wall_x = calc.ray_pos_x + calc.wall_dist * calc.ray_dir_x;
	wall_x = wall_x - (int)wall_x;
	SDL_QueryTexture(sdl->wall, NULL, NULL, &sdl->src.w, &sdl->src.h);
	sdl->src.x = wall_x * sdl->src.w;
	sdl->src.w = 1;
	sdl->src.y = 0;
	draw.line_height = (int)HEIGHT / calc.wall_dist;
	draw.draw_s = -draw.line_height / 2 + HEIGHT / 2;
	draw.draw_e = draw.line_height / 2 + HEIGHT / 2;
	sdl->dest.x = x;
	sdl->dest.h = draw.draw_e - draw.draw_s;
	sdl->dest.y = draw.draw_s;
	sdl->dest.w = 1;
	SDL_RenderCopy(sdl->render, sdl->wall, &sdl->src, &sdl->dest);
}

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

	y = -1;
	color = SDL_MapRGBA(sdl->format, 101, 217, 240, 255);
	SDL_LockTexture(sdl->saf, NULL, &sdl->tmp, &sdl->pitch);
	sdl->pixels = sdl->tmp;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			sdl->pixels[x + (y * WIDTH)] = color;
	}
	y--;
	color = SDL_MapRGBA(sdl->format, 64, 64, 64, 255);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			sdl->pixels[x + (y * WIDTH)] = color;
	}
	SDL_UnlockTexture(sdl->saf);
}
