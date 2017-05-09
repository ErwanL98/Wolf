/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:05:47 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/09 14:01:50 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void		ft_init_sdl(t_sdl *sdl)
{
	if((SDL_SetRelativeMouseMode(SDL_TRUE)) != 0)
		ft_sdl_error();
	if ((SDL_Init(SDL_INIT_VIDEO) || TTF_Init()) != 0)
		ft_sdl_error();
	if ((sdl->win = SDL_CreateWindow("Win", SDL_WINDOWPOS_CENTERED, \
			SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)) == NULL)
		ft_sdl_error();
	if ((sdl->render = SDL_CreateRenderer(sdl->win, -1, 0)) == NULL)
		ft_sdl_error();
	ft_init_color(sdl);
	if ((sdl->font = TTF_OpenFont("fonts/wolf.ttf", 75)) == NULL)
		ft_sdl_error();
	ft_init_saf(sdl);
	sdl->format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	SDL_SetRenderDrawColor(sdl->render, 255, 255, 255, 255);
	SDL_RenderClear(sdl->render);
}

void		ft_init_saf(t_sdl *sdl)
{
	if ((sdl->game[TFLOOR] = SDL_CreateTexture(sdl->render, \
					SDL_PIXELFORMAT_RGBA8888, \
					SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT * 2)) == NULL)
		ft_sdl_error();
	sdl->menu[IMG] = ft_create_texture("./img/menu.bmp", sdl);
}

void		ft_aff(t_sdl *sdl, t_def def)
{
	sdl->dst[DFLOOR].y = HEIGHT / 2 + sdl->y;
	sdl->dst[DFLOOR].x = 0;
	sdl->dst[DFLOOR].w = WIDTH;
	sdl->dst[DFLOOR].h = HEIGHT * 2;
	SDL_SetRenderDrawColor(sdl->render, 0, 0, 0, 255);
	SDL_RenderClear(sdl->render);
	SDL_RenderCopy(sdl->render, sdl->game[TSKY], &sdl->src[SSKY], &sdl->dst[DSKY]);
	SDL_RenderCopy(sdl->render, sdl->game[TFLOOR], NULL, &sdl->dst[DFLOOR]);
	ft_loop(def, sdl);
	ft_draw_minimap(sdl, def);
	SDL_RenderCopy(sdl->render, sdl->game[TMAP], NULL, &sdl->dst[DMAP]);
	SDL_RenderPresent(sdl->render);
}

SDL_Texture	*ft_create_texture(char *path, t_sdl *sdl)
{
	SDL_Texture		*new;

	if ((sdl->load[TEXTURE] = SDL_LoadBMP(path)) == NULL)
		ft_sdl_error();
	if ((new = SDL_CreateTextureFromSurface(sdl->render, \
					sdl->load[TEXTURE])) == NULL)
		ft_sdl_error();
	SDL_FreeSurface(sdl->load[TEXTURE]);
	return (new);
}
