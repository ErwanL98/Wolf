/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:46:06 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/09 13:38:37 by ele-cren         ###   ########.fr       */
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

void	ft_mouse1(t_sdl *sdl, t_def *def)
{
	if (sdl->in.x_rel < 0)
	{
		def->o_dir_x = def->dir_x;
		def->dir_x = def->dir_x * cos(-def->r_speed * 1.5 * M_PI / 180) - \
					def->dir_y * sin(-def->r_speed * 1.5 *  M_PI / 180);
		def->dir_y = def->o_dir_x * sin(-def->r_speed * 1.5 * M_PI / 180) + \
					def->dir_y * cos(-def->r_speed * 1.5 * M_PI / 180);
		def->o_plane_x = def->plane_x;
		def->plane_x = def->plane_x * cos(-def->r_speed * 1.5 * M_PI / 180) - \
					  def->plane_y * sin(-def->r_speed * 1.5 * M_PI / 180);
		def->plane_y = def->o_plane_x * sin(-def->r_speed * 1.5 * M_PI / 180) + \
					  def->plane_y * cos(-def->r_speed * 1.5 * M_PI / 180);
		sdl->src[SSKY].x -= (WIDTH / 66 * 2.5);
		if (sdl->src[SSKY].x < 0)
			sdl->src[SSKY].x = sdl->width_sky - WIDTH;
	}
	ft_mouse2(sdl, def);
}

void	ft_mouse2(t_sdl *sdl, t_def *def)
{
	if (sdl->in.x_rel > 0)
	{
		def->o_dir_x = def->dir_x;
		def->dir_x = def->dir_x * cos(def->r_speed * 1.5 * M_PI / 180) - \
					def->dir_y * sin(def->r_speed * 1.5 * M_PI / 180);
		def->dir_y = def->o_dir_x * sin(def->r_speed * 1.5 * M_PI / 180) + \
					def->dir_y * cos(def->r_speed * 1.5 * M_PI / 180);
		def->o_plane_x = def->plane_x;
		def->plane_x = def->plane_x * cos(def->r_speed * 1.5 * M_PI / 180) - \
					  def->plane_y * sin(def->r_speed * 1.5 * M_PI / 180);
		def->plane_y = def->o_plane_x * sin(def->r_speed * 1.5 * M_PI / 180) + \
					  def->plane_y * cos(def->r_speed * 1.5 * M_PI / 180);
		sdl->src[SSKY].x += (WIDTH / 66 * 2.5);
		if (sdl->src[SSKY].x > (sdl->width_sky - WIDTH))
			sdl->src[SSKY].x = 0;
	}
	if (sdl->in.y_rel < -2 && sdl->y <= 373)
		sdl->y += 20;
	if (sdl->in.y_rel > 2 && sdl->y >= -600)
		sdl->y -= 20;
}
