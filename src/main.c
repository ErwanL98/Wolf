/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 11:04:57 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/16 17:11:46 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int		main(int ac, char **av)
{
	t_sdl	sdl;

	(void)av;
	if (ac == 1)
	{
		ft_init_sdl(&sdl);
		ft_draw_saf(&sdl);
		//ft_game(&sdl, "./maps/42.map", 1);
		ft_select(&sdl);
	}
	else
		ft_putendl("Usage : ./wolf3d");
	return (0);
}

void	ft_fps(t_sdl *sdl, t_def *def)
{
	char	*fps;

	fps = NULL;
	def->o_time = def->time;
	def->time = SDL_GetTicks();
	def->frame_time = (def->time - def->o_time) / 1000;
	def->w_time += def->frame_time;
	if (def->w_time == 0 || def->w_time > 0.2)
	{
		fps = ft_freestrjoin(ft_itoa((int)(1 / def->frame_time)), " FPS", 1);
		if ((sdl->load[TTF] = TTF_RenderText_Blended(sdl->font2, fps, \
										sdl->color[0])) == NULL)
			ft_sdl_error();
		if ((sdl->game[TFPS] = SDL_CreateTextureFromSurface(sdl->render, \
						sdl->load[TTF])) == NULL)
			ft_sdl_error();
		SDL_QueryTexture(sdl->game[TFPS], NULL, NULL, \
				&sdl->dst[DFPS].w, &sdl->dst[DFPS].h);
		sdl->dst[DFPS].x = WIDTH - sdl->dst[DFPS].w - 10;
		sdl->dst[DFPS].y = 5;
		SDL_FreeSurface(sdl->load[TTF]);
		def->w_time = 0;
		free(fps);
	}
}

void	ft_game(t_sdl *sdl, char *map, int select)
{
	t_def	def;
	t_parse	parse;

	ft_init(&def, sdl, &parse, map);
	if (select == 1 || select == 2)
		(select == 1) ? ft_init_42(&def) : ft_init_1(&def);
	else if (select == 3)
		ft_init_2(&def);
	ft_display(sdl, &def);
	while (sdl->keep_game == 1)
	{
		sdl->in.x_rel = 0;
		sdl->in.y_rel = 0;
		ft_event(sdl);
		def.m_speed = 0.0375;
		ft_fps(sdl, &def);
		ft_power(sdl, &def);
		ft_mouse1(sdl, &def);
		sdl->wallbreak.pos_x = 0;
		sdl->wallbreak.pos_y = 0;
		ft_display(sdl, &def);
		SDL_Delay(8);
	}
	SDL_RenderClear(sdl->render);
	ft_freegame(sdl, &def, parse);
}
