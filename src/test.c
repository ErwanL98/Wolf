/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:52:08 by ele-cren          #+#    #+#             */
/*   Updated: 2017/04/18 15:12:13 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <SDL_ttf.h>

int		main(void)
{
	SDL_Renderer	*render;
	SDL_Window		*win;
	int				keep;
	SDL_Event		event;
	SDL_Surface		*text;
	SDL_Color		white = {255, 255, 255};
	TTF_Font		*font;
	SDL_Texture		*texture;
	SDL_Rect		pos;

	keep = 1;
	TTF_Init();
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (0);
	if ((win = SDL_CreateWindow("Win", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN)) == NULL)
		return (0);
	if ((render = SDL_CreateRenderer(win, -1, 0)) == NULL)
		return (0);
	SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
	font = TTF_OpenFont("times.ttf", 25);
	text = TTF_RenderText_Blended(font, "Salut Salut mon ami", white);
	texture = SDL_CreateTextureFromSurface(render, text);	
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	pos.x = 0;
	pos.y = 0;
	while (keep == 1)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			keep = 0;
		SDL_RenderClear(render);
		SDL_RenderCopy(render, texture, NULL, &pos);
		SDL_RenderPresent(render);
	}
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(text);
	TTF_CloseFont(font);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	TTF_Quit();
	SDL_Quit();
}
