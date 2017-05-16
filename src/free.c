/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:14:30 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/16 16:21:19 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_free(t_sdl *sdl)
{
	SDL_DestroyWindow(sdl->win);
	SDL_DestroyRenderer(sdl->render);
	SDL_FreeFormat(sdl->format);
	SDL_DestroyTexture(sdl->menu[MENU]);
	SDL_DestroyTexture(sdl->menu[IMG]);
	SDL_DestroyTexture(sdl->game[TSKY]);
	SDL_DestroyTexture(sdl->game[TFLOOR]);
	TTF_CloseFont(sdl->font);
	TTF_CloseFont(sdl->font2);
	TTF_Quit();
	SDL_Quit();
}

void	ft_freegame(t_sdl *sdl, t_def *def, t_parse parse)
{
	ft_inttabdel(&def->tab, parse.height);
	SDL_DestroyTexture(sdl->game[TWALLB]);
	SDL_DestroyTexture(sdl->game[TMAP]);
	SDL_DestroyTexture(sdl->game[TGUN]);
	SDL_DestroyTexture(sdl->game[TSHOTGUN]);
	SDL_DestroyTexture(sdl->game[TWEAPONS]);
	SDL_DestroyTexture(sdl->game[TWALL]);
	SDL_DestroyTexture(sdl->game[TFPS]);
}
