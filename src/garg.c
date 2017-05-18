/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garg.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:02:45 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/18 15:51:50 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_disp_garg(t_def *def, t_sdl *sdl, t_calc calc)
{
	def->garg.i = -1;
	ft_init_garg(def, sdl);
	def->garg.drect.w = 1;
	while (++def->garg.i < def->garg.rect.h / 2)
	{
		calc.camera_x = 2 * def->garg.rect.x / (double)WIDTH - 1;
		calc.ray_pos_x = def->pos_x;
		calc.ray_pos_y = def->pos_y;
		calc.ray_dir_x = def->dir_x + def->plane_x * calc.camera_x;
		calc.ray_dir_y = def->dir_y + def->plane_y * calc.camera_x;
		ft_check_wall(*def, &calc);
		if (calc.wall_dist > def->garg.dist)
		{
			def->garg.disp_life = 1;
			def->garg.f_x = (def->garg.f_x == 0) ? def->garg.rect.x + \
							(def->garg.rect.w) / 2 : def->garg.f_x;
			def->garg.l_x = def->garg.rect.x;
			SDL_RenderCopy(sdl->render, sdl->game[RGARG], &def->garg.drect, \
					&def->garg.rect);
		}
		def->garg.rect.x++;
		def->garg.drect.x++;
	}
	ft_destroy_garg(def, sdl);
}

void	ft_destroy_garg(t_def *def, t_sdl *sdl)
{
	SDL_DestroyTexture(sdl->game[RGARG]);
	def->garg.x = 0;
	def->garg.disp = 0;
}

void	ft_init_garg(t_def *def, t_sdl *sdl)
{
	def->garg.drect.x = 0;
	def->garg.drect.y = 0;
	def->garg.dist = sqrt(pow(def->garg.pos_x - def->pos_x, 2) + \
			pow(def->garg.pos_y - def->pos_y, 2));
	def->garg.dist = (def->garg.dist < 0.1) ? 0.1 : def->garg.dist;
	def->garg.rect.h = HEIGHT / def->garg.dist;
	def->garg.rect.y = -def->garg.rect.h / 2 + HEIGHT / 2 + sdl->y + 10;
	def->garg.rect.w = def->garg.rect.h / 2;
	def->garg.f_x = 0;
	def->garg.l_x = -(def->garg.rect.w) / 2;
	def->garg.rect.x = def->garg.x - (def->garg.rect.w) / 2;
	sdl->dst[DLIFE].x = def->garg.rect.x;
	if ((sdl->game[RGARG] = SDL_CreateTexture(sdl->render, \
					SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, \
					def->garg.rect.w, def->garg.rect.h)) == NULL)
		ft_sdl_error();
	SDL_SetRenderTarget(sdl->render, sdl->game[RGARG]);
	SDL_SetRenderDrawColor(sdl->render, 255, 255, 255, 1);
	SDL_RenderClear(sdl->render);
	def->garg.rect.w = 1;
	SDL_RenderCopy(sdl->render, sdl->game[GARG], NULL, NULL);
	SDL_SetTextureBlendMode(sdl->game[RGARG], SDL_BLENDMODE_BLEND);
	SDL_SetRenderTarget(sdl->render, NULL);
	SDL_QueryTexture(sdl->game[RGARG], NULL, NULL, &def->garg.drect.w, \
									&def->garg.drect.h);
}
