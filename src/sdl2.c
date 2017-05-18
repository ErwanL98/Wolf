/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:25:24 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/18 15:29:06 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_copy(t_sdl *sdl, t_def *def)
{
	SDL_SetRenderDrawColor(sdl->render, 0, 0, 0, 255);
	SDL_RenderClear(sdl->render);
	SDL_RenderCopy(sdl->render, sdl->game[TSKY], &sdl->src[SSKY], \
			&sdl->dst[DSKY]);
	SDL_RenderCopy(sdl->render, sdl->game[TFLOOR], NULL, &sdl->dst[DFLOOR]);
	ft_loop(def, sdl);
	ft_draw_minimap(sdl, *def);
	SDL_RenderCopy(sdl->render, sdl->game[TWEAPONS], NULL, &sdl->dst[DWEAPONS]);
	SDL_RenderCopy(sdl->render, sdl->game[TMAP], NULL, &sdl->dst[DMAP]);
	SDL_RenderCopy(sdl->render, sdl->game[TFPS], NULL, &sdl->dst[DFPS]);
}
