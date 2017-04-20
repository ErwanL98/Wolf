/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:46:06 by ele-cren          #+#    #+#             */
/*   Updated: 2017/04/20 17:28:08 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_key_menu(t_sdl *sdl, int *select)
{
	if (sdl->event_menu.key.keysym.sym == SDLK_DOWN)
		*select = (*select == 4) ? 1 : *select + 1;
	else if (sdl->event_menu.key.keysym.sym == SDLK_UP)
		*select = (*select == 1) ? 4 : *select - 1;
	else if (sdl->event_menu.key.keysym.sym == SDLK_RETURN)
	{
		if (*select == 1)
			ft_game(sdl, "./maps/42.map", *select);
		else if (*select == 2)
			ft_game(sdl, "./maps/a.map", *select);
		else if (*select == 3)
			ft_game(sdl, "./maps/b.map", *select);
		else if (*select == 4)
			sdl->keep_menu = 0;
	}
	else if (sdl->event_menu.key.keysym.sym == SDLK_ESCAPE)
		sdl->keep_menu = 0;
}
