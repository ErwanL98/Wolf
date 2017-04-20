/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:27:11 by ele-cren          #+#    #+#             */
/*   Updated: 2017/04/20 17:49:05 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_menu(t_sdl *sdl, int select)
{
	if ((sdl->menu[MENU] = SDL_CreateTexture(sdl->render, \
					SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, \
					WIDTH, HEIGHT)) == NULL)
		ft_sdl_error();
	SDL_SetRenderTarget(sdl->render, sdl->menu[MENU]);
	SDL_RenderCopy(sdl->render, sdl->menu[IMG], NULL, NULL);
	ft_text(sdl, 1, select);
	ft_text(sdl, 2, select);
	ft_text(sdl, 3, select);
	ft_text(sdl, 4, select);
	SDL_SetRenderTarget(sdl->render, NULL);
	SDL_RenderCopy(sdl->render, sdl->menu[MENU], NULL, NULL);
	SDL_RenderPresent(sdl->render);
}

void	ft_text_cases(t_sdl *sdl, int text, int select)
{
	if (text == 1)
	{
		if ((sdl->tmp_menu = TTF_RenderText_Blended(sdl->font, "Map 42", \
						sdl->color[(select == 1) ? 1 : 0])) == NULL)
			ft_sdl_error();
	}
	else if (text == 2)
	{
		if ((sdl->tmp_menu = TTF_RenderText_Blended(sdl->font, "Level 1", \
						sdl->color[(select == 2) ? 1 : 0])) == NULL)
			ft_sdl_error();
	}
	else if (text == 3)
	{
		if ((sdl->tmp_menu = TTF_RenderText_Blended(sdl->font, "Level 2", \
						sdl->color[(select == 3) ? 1 : 0])) == NULL)
			ft_sdl_error();
	}
	else if (text == 4)
	{
		if ((sdl->tmp_menu = TTF_RenderText_Blended(sdl->font, "Exit", \
						sdl->color[(select == 4) ? 1 : 0])) == NULL)
			ft_sdl_error();
	}

}

void	ft_text(t_sdl *sdl, int text, int select)
{
	static int	i = 0;

	ft_text_cases(sdl, text, select);
	if ((sdl->menu[TEXT] = SDL_CreateTextureFromSurface(sdl->render, \
					sdl->tmp_menu)) == NULL)
		ft_sdl_error();
	SDL_SetTextureAlphaMod(sdl->menu[TEXT], 190);
	SDL_QueryTexture(sdl->menu[TEXT], NULL, NULL, &sdl->postext.w, \
			&sdl->postext.h);
	sdl->postext.x = ((WIDTH / 2) - (sdl->postext.w / 2)) + 10;
	sdl->postext.y = 340 + i;
	SDL_FreeSurface(sdl->tmp_menu);
	SDL_RenderCopy(sdl->render, sdl->menu[TEXT], NULL, &sdl->postext);
	SDL_DestroyTexture(sdl->menu[TEXT]);
	i = (i == 210) ? 0 : i + 70;
}

void	ft_select(t_sdl *sdl)
{
	int		select;

	select = 1;
	sdl->keep_menu = 1;
	ft_menu(sdl, select);
	while (sdl->keep_menu == 1)
	{
		SDL_WaitEvent(&sdl->event_menu);
		if (sdl->event_menu.type == SDL_QUIT)
			sdl->keep_menu = 0;
		if (sdl->event_menu.type == SDL_KEYDOWN)
			ft_key_menu(sdl, &select);
		SDL_DestroyTexture(sdl->menu[MENU]);
		SDL_RenderClear(sdl->render);
		ft_menu(sdl, select);
	}
	ft_free(sdl);
}
