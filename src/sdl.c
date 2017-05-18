/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:05:47 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/18 16:59:35 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void		ft_init_sdl(t_sdl *sdl)
{
	if ((SDL_Init(SDL_INIT_VIDEO) || TTF_Init()) != 0)
		ft_sdl_error();
	if ((SDL_SetRelativeMouseMode(SDL_TRUE)) != 0)
		ft_sdl_error();
	if ((sdl->win = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED, \
			SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)) == NULL)
		ft_sdl_error();
	if ((sdl->render = SDL_CreateRenderer(sdl->win, -1, 0)) == NULL)
		ft_sdl_error();
	ft_init_color(sdl);
	if ((sdl->font = TTF_OpenFont("fonts/wolf.ttf", 75)) == NULL)
		ft_sdl_error();
	ft_init_saf(sdl);
	if ((sdl->font2 = TTF_OpenFont("fonts/wolf.ttf", 35)) == NULL)
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
	sdl->menu[IMG] = ft_create_texture("./img/menu.bmp", sdl, 0);
}

void		ft_display(t_sdl *sdl, t_def *def)
{
	sdl->dst[DFLOOR].y = HEIGHT / 2 + sdl->y;
	sdl->dst[DFLOOR].x = 0;
	sdl->dst[DFLOOR].w = WIDTH;
	sdl->dst[DFLOOR].h = HEIGHT * 2;
	ft_copy(sdl, def);
	if (def->garg.disp == 1 && def->garg.dead == 0)
	{
		ft_disp_garg(def, sdl, def->garg.calc);
		sdl->dst[DLIFE].y = def->garg.rect.y - 70;
		if (def->garg.disp_life == 1)
		{
			ft_draw_life(*def, sdl);
			SDL_RenderCopy(sdl->render, sdl->game[TLIFE], NULL, \
														&sdl->dst[DLIFE]);
		}
		def->garg.disp_life = 0;
	}
	ft_display_guns(sdl, def);
	SDL_RenderPresent(sdl->render);
}

void		ft_display_guns(t_sdl *sdl, t_def *def)
{
	if (def->weapon == 1)
	{
		(def->fire == 0) ? SDL_RenderCopy(sdl->render, sdl->game[TGUN], NULL, \
			&sdl->dst[DGUN]) : SDL_RenderCopy(sdl->render, \
				sdl->game[TGUN2], NULL, &sdl->dst[DGUN]);
		def->fire = (def->fire == 1) ? 0 : def->fire;
	}
	else if (def->weapon == 2)
	{
		(def->fire == 0) ? SDL_RenderCopy(sdl->render, sdl->game[TSHOTGUN], \
				NULL, &sdl->dst[DSHOTGUN]) : SDL_RenderCopy(sdl->render, \
					sdl->game[TSHOTGUN2], NULL, &sdl->dst[DSHOTGUN]);
		def->fire = (def->fire == 1) ? 0 : def->fire;
	}
}

SDL_Texture	*ft_create_texture(char *path, t_sdl *sdl, int mod)
{
	SDL_Texture		*new;

	if ((sdl->load[TEXTURE] = SDL_LoadBMP(path)) == NULL)
		ft_sdl_error();
	if (mod == 1)
		SDL_SetColorKey(sdl->load[TEXTURE], SDL_TRUE, \
				SDL_MapRGBA(sdl->load[TEXTURE]->format, 0, 255, 255, 255));
	if ((new = SDL_CreateTextureFromSurface(sdl->render, \
					sdl->load[TEXTURE])) == NULL)
		ft_sdl_error();
	SDL_FreeSurface(sdl->load[TEXTURE]);
	return (new);
}
