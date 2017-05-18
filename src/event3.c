/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:18:40 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/18 16:41:43 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_cam_r(t_sdl *sdl, t_def *def)
{
	if (sdl->in.key[SDL_SCANCODE_RIGHT])
	{
		def->o_dir_x = def->dir_x;
		def->dir_x = def->dir_x * cos(def->r_speed * M_PI / 180) - \
					def->dir_y * sin(def->r_speed * M_PI / 180);
		def->dir_y = def->o_dir_x * sin(def->r_speed * M_PI / 180) + \
					def->dir_y * cos(def->r_speed * M_PI / 180);
		def->o_plane_x = def->plane_x;
		def->plane_x = def->plane_x * cos(def->r_speed * M_PI / 180) - \
						def->plane_y * sin(def->r_speed * M_PI / 180);
		def->plane_y = def->o_plane_x * sin(def->r_speed * M_PI / 180) + \
						def->plane_y * cos(def->r_speed * M_PI / 180);
		sdl->src[SSKY].x += (WIDTH / 66 * def->r_speed);
		if (sdl->src[SSKY].x > (sdl->width_sky - WIDTH))
			sdl->src[SSKY].x = WIDTH;
	}
	ft_cam_lud(sdl, def);
}

void	ft_cam_lud(t_sdl *sdl, t_def *def)
{
	if (sdl->in.key[SDL_SCANCODE_LEFT])
	{
		def->o_dir_x = def->dir_x;
		def->dir_x = def->dir_x * cos(-def->r_speed * M_PI / 180) - \
						def->dir_y * sin(-def->r_speed * M_PI / 180);
		def->dir_y = def->o_dir_x * sin(-def->r_speed * M_PI / 180) + \
						def->dir_y * cos(-def->r_speed * M_PI / 180);
		def->o_plane_x = def->plane_x;
		def->plane_x = def->plane_x * cos(-def->r_speed * M_PI / 180) - \
						def->plane_y * sin(-def->r_speed * M_PI / 180);
		def->plane_y = def->o_plane_x * sin(-def->r_speed * M_PI / 180) + \
						def->plane_y * cos(-def->r_speed * M_PI / 180);
		sdl->src[SSKY].x -= (WIDTH / 66 * def->r_speed);
		if (sdl->src[SSKY].x < 0)
			sdl->src[SSKY].x = sdl->width_sky - (WIDTH * 2);
	}
	if (sdl->in.key[SDL_SCANCODE_UP] && sdl->y <= 373)
		sdl->y += 20;
	if (sdl->in.key[SDL_SCANCODE_DOWN] && sdl->y >= -600)
		sdl->y -= 20;
	if (sdl->in.key[SDL_SCANCODE_ESCAPE])
		sdl->keep_game = 0;
}

void	ft_power(t_sdl *sdl, t_def *def)
{
	def->m_speed *= (sdl->in.key[SDL_SCANCODE_LSHIFT]) ? 1.5 : 1;
	if (sdl->in.key[SDL_SCANCODE_1] && sdl->in.key[SDL_SCANCODE_2] == 0)
		def->weapon = 1;
	if (sdl->in.key[SDL_SCANCODE_2] && sdl->in.key[SDL_SCANCODE_1] == 0)
		def->weapon = 2;
	if (sdl->in.key[SDL_SCANCODE_SPACE] || sdl->in.button[SDL_BUTTON_LEFT])
	{
		def->fire = 1;
		if (sdl->wallbreak.breakable == 1 && def->weapon == 2)
		{
			def->tab[sdl->wallbreak.pos_y][sdl->wallbreak.pos_x] = -1;
			sdl->wallbreak.breakable = 0;
			sdl->in.button[SDL_BUTTON_LEFT] = 0;
		}
		else if ((WIDTH / 2 >= def->garg.f_x && WIDTH / 2 <= def->garg.l_x) && \
				(def->garg.time >= 0.3 || def->garg.time == 0) && \
				(sdl->dst[DGUN].y + 145 >= def->garg.rect.y && sdl->dst[DGUN].y\
				+ 145 <= def->garg.rect.h + def->garg.rect.y))
		{
			def->garg.life -= (def->weapon == 1) ? 25 : 50;
			def->garg.dead = (def->garg.life <= 0) ? 1 : 0;
			def->garg.time = 0;
		}
	}
	ft_move_f(sdl, def);
}
