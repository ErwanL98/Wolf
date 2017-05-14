/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:36:03 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/10 16:13:35 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_event(t_sdl *sdl)
{
	while (SDL_PollEvent(&sdl->event_game))
	{
		if (sdl->event_game.type == SDL_QUIT)
			sdl->keep_game = 0;
		if (sdl->event_game.type == SDL_KEYDOWN)
			sdl->in.key[sdl->event_game.key.keysym.scancode] = 1;
		else if (sdl->event_game.type == SDL_KEYUP)
			sdl->in.key[sdl->event_game.key.keysym.scancode] = 0;
		if (sdl->event_game.type == SDL_MOUSEBUTTONDOWN)
			sdl->in.button[sdl->event_game.button.button] = 1;
		else if (sdl->event_game.type == SDL_MOUSEBUTTONUP)
			sdl->in.button[sdl->event_game.button.button] = 0;
		if (sdl->event_game.type == SDL_MOUSEMOTION)
		{
			sdl->in.x_rel += sdl->event_game.motion.xrel;
			sdl->in.y_rel += sdl->event_game.motion.yrel;
		}
	}
}

void	ft_is_key(t_sdl *sdl, t_def *def)
{
	if (sdl->in.key[SDL_SCANCODE_LSHIFT])
		def->m_speed *= 1.5;
	if (sdl->in.key[SDL_SCANCODE_1] && sdl->in.key[SDL_SCANCODE_2] == 0)
		def->weapon = 1;
	if (sdl->in.key[SDL_SCANCODE_2] && sdl->in.key[SDL_SCANCODE_1] == 0)
		def->weapon = 2;
	if (sdl->in.key[SDL_SCANCODE_SPACE] || sdl->in.button[SDL_BUTTON_LEFT])
		def->fire = 1;
	if (sdl->in.key[SDL_SCANCODE_W])
	{
		if (def->tab[(int)def->pos_y][(int)(def->pos_x + def->dir_x * \
					def->m_speed)] == 0)
			def->pos_x += def->dir_x * def->m_speed;
		if (def->tab[(int)(def->pos_y + def->dir_y * \
					def->m_speed)][(int)def->pos_x] == 0)
			def->pos_y += def->dir_y * def->m_speed;
	}
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
			sdl->src[SSKY].x = sdl->width_sky - WIDTH;
	}
	ft_is_key2(sdl, def);
}

void	ft_is_key2(t_sdl *sdl, t_def *def)
{
	if (sdl->in.key[SDL_SCANCODE_S])
	{
		if (def->tab[(int)def->pos_y][(int)(def->pos_x - def->dir_x * \
					def->m_speed)] == 0)
			def->pos_x -= def->dir_x * def->m_speed;
		if (def->tab[(int)(def->pos_y - def->dir_y * \
					def->m_speed)][(int)def->pos_x] == 0)
			def->pos_y -= def->dir_y * def->m_speed;
	}
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
			sdl->src[SSKY].x = 0;
	}
	if (sdl->in.key[SDL_SCANCODE_A])
	{
		if (def->tab[(int)def->pos_y][(int)(def->pos_x - def->plane_x * \
												def->m_speed)] == 0)
			def->pos_x -= def->plane_x * def->m_speed;
		if (def->tab[(int)(def->pos_y - def->plane_y * \
								def->m_speed)][(int)def->pos_x] == 0)
			def->pos_y -= def->plane_y * def->m_speed;
	}
	if (sdl->in.key[SDL_SCANCODE_D])
	{
		if (def->tab[(int)def->pos_y][(int)(def->pos_x + def->plane_x * \
												def->m_speed)] == 0)
			def->pos_x += def->plane_x * def->m_speed;
		if (def->tab[(int)(def->pos_y + def->plane_y * \
								def->m_speed)][(int)def->pos_x] == 0)
			def->pos_y += def->plane_y * def->m_speed;
	}
	if (sdl->in.key[SDL_SCANCODE_UP] && sdl->y <= 373)
		sdl->y += 20;
	if (sdl->in.key[SDL_SCANCODE_DOWN] && sdl->y >= -600)
		sdl->y -= 20;
	if (sdl->in.key[SDL_SCANCODE_ESCAPE])
		sdl->keep_game = 0;
}
